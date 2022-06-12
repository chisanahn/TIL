# 2022년도 1학기 오픈소스전문프로젝트 교과목(안드로이드 개발)

## DB

상품 정보와 사용자들이 해당 상품들에 대해서 북마크를 할 수 있도록 관리하는 기능 개발

* 사용자들이 offline으로도 이용할 수 있도록 따로 서버를 두지 않고 내장 DB(SQLite)를 이용해서 구현했고, 이를 위해서 `Room` 라이브러리를 사용했다.

  상품 정보는 웹크롤링을 이용해서 정보를 수집하고 SQLite 파일 형태로 저장해서, 앱을 배포할때 assets 폴더에 넣어서 배포하고, `Room` 라이브러리의 `createFromAssets()` 메소드를 사용했다.

* 처음에 북마크 정보를 상품 table에 column 값으로 관리하는 식으로 구현했었는데, 이렇게 구현하자 북마크 정보가 앱을 다시 실행할때마다 초기화되는 문제가 생겼다.

  > `createFromAssets()` 메소드가 앱을 실행할때마다 호출되면서 사용자가 수정한 정보가 초기화되버린다.

* 그래서 상품 정보와 북마크 정보를 2개의 database로 나눠서 관리하는 방식으로 구현했다.

  > 서로 다른 database의 table 간에 FK 관계를 설정할 수 없어서 이 방법이 맞나 싶었지만 다른 방법이 생각나지 않았다.

<br><br>

## Github Actions를 활용한 CI/CD 구축

<br>

### 1. `atto-webcrawling` repository에서 웹크롤링 후 생성된 db를 `atto` repository로 push

* https://github.com/marketplace/actions/push-directory-to-another-repository 를 사용했다.

  도중에 인증오류가 발생했지만,

  ```
  remote: Invalid username or password.
  fatal: Authentication failed for 'https://github.com/cbnuEarthProtector/atto.git/'
  ```

  README와 예제코드를 다시 한번 주의깊게 살펴보면서 `API_TOKEN_GITHUB` 없이 `SSH_DEPLOY_KEY`만 사용할 수 있다는걸 알아내고 해결했다.

  ```
  uses: cpina/github-action-push-to-another-repository@ssh-deploy-key
  ```

<br>

### 2. 자동으로 java 파일 실행

* gradle을 사용중이라 다음과 같은 명령어로 간단하게 build 후 실행할 수 있었다.

  ```
  ./gradlew run
  ```
  https://docs.gradle.org/current/samples/sample_building_java_applications.html

* 다음과 같은 오류가 발생했는데 구글링을 해봐도 해결이 잘 안돼서 좀 고생했는데

  ```
  Execution failed for task ':compileJava'.
  > invalid source release: 14
  ```

  알고보니 gradlew 파일을 확인해보면 `$JAVA_HOME`을 기준으로 동작해서 환경변수의 자바 버전도 동일하게 맞춰줘야 한다.

  > 환경변수 수정이 반영되려면 컴퓨터를 껐다가 키는게 빠른 것 같다.

* github actions에서 gradle을 실행하는 것도 이미 좋은 오픈소스가 있어서 활용했다.
https://github.com/marketplace/actions/gradle-build-action

* github actions를 수동으로 실행하려면 `on: ` 부분에 값들을 설정해주면 된다.
https://levelup.gitconnected.com/how-to-manually-trigger-a-github-actions-workflow-4712542f1960

* github actions 전반적인 문법
https://docs.github.com/en/actions/using-workflows/workflow-syntax-for-github-actions#jobs

* github actions에서 cron은 default나 base branch에서만 동작한다고 한다.
https://stackoverflow.com/questions/63436541/github-action-workflow-schedule-not-working-on-non-default-branch

* `needs: `로 job 간에 의존성을 설정할 수 있다.
https://stackoverflow.com/questions/63148639/create-dependencies-between-jobs-in-github-actions

* chrome driver를 실행하기 위해서 몇가지 github actions를 더 사용했다.

  * https://github.com/nanasess/setup-chromedriver

  * https://github.com/browser-actions/setup-chrome

  > chromedriver와 버전을 맞추기 위해서 `stable` 버전 chrome을 설치했다.

<details><summary>결과물</summary>

```yaml
name: CI

on:
  schedule:
    - cron: 0 0 * * * # daily

  workflow_dispatch:

jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v2
      - uses: nanasess/setup-chromedriver@v1
        with:
          # Optional: do not specify to match Chrome's version
          chromedriver-version: '102.0.5005.61'
      - run: |
          export DISPLAY=:99
          chromedriver --url-base=/wd/hub &
          sudo Xvfb -ac :99 -screen 0 1280x1024x24 > /dev/null 2>&1 & # optional
      - uses: browser-actions/setup-chrome@latest
        with:
          chrome-version: stable
      - run: chrome --version

      - uses: actions/checkout@v3
      - uses: actions/setup-java@v3
        with:
          distribution: microsoft
          java-version: 16

      - name: Setup Gradle
        uses: gradle/gradle-build-action@v2

      - name: mv chromedriver
        run: sudo mv /usr/local/bin/chromedriver ./chromedriver.exe

      - name: Execute Gradle run
        run: ./gradlew run

  push:
    needs: build
    
    # The type of runner that the job will run on
    runs-on: ubuntu-latest

    # Steps represent a sequence of tasks that will be executed as part of the job
    steps:
      # Checks-out your repository under $GITHUB_WORKSPACE, so your job can access it
      - uses: actions/checkout@v3

      - name: Push directory to another repository
        uses: cpina/github-action-push-to-another-repository@ssh-deploy-key
        env:
          SSH_DEPLOY_KEY: ${{ secrets.SSH_DEPLOY_KEY }}
        with:
          source-directory: 'database'
          destination-github-username: 'cbnuEarthProtector'
          destination-repository-name: 'atto'
          user-email: chisan2001@gmail.com
          target-branch: db-update
          target-directory: 'app/src/main/assets/database'
```
</details>

<br><br>

### 3. 안드로이드 앱 build 후 github release에 배포

* github에 기초적인 에제가 있어서 이걸 토대로 프로젝트에 맞게 변경하고 있다.
https://gist.github.com/alexanderbazo/227476190ef5ab655795e34ec0d314d6

  build하는 부분은 java version만 프로젝트에 맞게 변경해주니깐 잘 작동했다.

  하지만 release 부분에서 어려움을 겪고 있다.

* Resource not accessible by integration 오류
https://stackoverflow.com/questions/70435286/resource-not-accessible-by-integration-on-github-post-repos-owner-repo-ac

* release를 생성해주는 github actions를 보면 tag를 사용해서 push해야 하는데 어떻게 하는건지 아직 잘 모르겠다.
https://github.com/softprops/action-gh-release

* apk release 성공

  완전 깔끔하진 않지만 아래의 github actions를 활용해서 성공했다.

  https://github.com/marvinpinto/action-automatic-releases#event-triggers

  > files 부분을 "**.apk"로 바꿨더니 잘 동작한다.

<br>

### 4. 배포할때마다 android version 자동으로 증가시키기

android version을 증가시켜야 사용자들이 새로 배포된 앱을 설치할때 기존 앱에서 업데이트를 수행할 수 있다.

* build.gradle에 저장된 android versionCode 출력하기 
https://stackoverflow.com/questions/35475432/read-versionname-from-build-gradle-in-bash

* GitHub Actions에서 gradle task 결과 환경변수에 저장하기
    * https://stackoverflow.com/questions/42523736/run-gradle-task-and-save-its-return-value-to-shell-script-variable
    * https://stackoverflow.com/questions/57968497/how-do-i-set-an-env-var-with-a-bash-expression-in-github-actions

* 환경변수 값 1 증가시키기
https://stackoverflow.com/questions/21035121/increment-variable-value-by-1-shell-programming

* `run: ` 이외의 곳에서 환경변수를 사용하려면 `${{ env.환경변수명 }}`과 같이 사용해야 한다.

* versionCode를 꾸준히 증가시켜주려면 versionCode 값을 변경한뒤에 main에 push 해줘야할듯
https://stackoverflow.com/questions/57921401/push-to-origin-from-github-action/58393457#58393457

<details><summary>결과물</summary>

```yaml
name: Minimal Android CI Workflow

on:
  push:
    branches:
      - main

jobs:
  apk:
    # prevent additional release
    if: ${{ github.event.head_commit.message }} != 'versionCode increased'

    name: Build & Deploy APK
    permissions: write-all
    runs-on: ubuntu-latest
    steps:
      - name: Checkout
        uses: actions/checkout@v2
        
      - name: Setup JDK
        uses: actions/setup-java@v1
        with:
          java-version: 11

      - name: store app version code
        run: echo "VERSION=$(bash ./gradlew -q printVersionCode | tail -n 1)" >> $GITHUB_ENV

      - name: increase app version code
        run: echo "VERSION=$((VERSION + 1))" >> $GITHUB_ENV

      - name: print app version code
        run: echo $VERSION

      - name: Update gradle version for Android
        uses: damienaicheh/update-android-version-gradle-action@v1.0.0
        with:
          build-gradle-path: './app/build.gradle'
          version-code: ${{ env.VERSION }}
          version-name: "${{ env.VERSION }}.0"
          print-file: true

      - name: Commit version update
        run: |
          git config --global user.name 'chisan01'
          git config --global user.email 'chisan2001@naver.com'
          git commit -am "versionCode increased"
          git push
      - name: Build APK
        run: bash ./gradlew assembleDebug --stacktrace

      - name: Release APK
        uses: "marvinpinto/action-automatic-releases@latest"
        with:
          repo_token: "${{ secrets.GITHUB_TOKEN }}"
          automatic_release_tag: "v.${{ env.VERSION }}"
          prerelease: false
          title: "v.${{ env.VERSION }}"
          files: "**.apk"
```
</details>