## 기존에 진행중인 프로젝트에서 git & github 연동하는 방법

1. Terminal에서 프로젝트 폴더로 이동 후 다음과 같은 명령어를 실행한다.

    > git bash의 경우 프로젝트 폴더 안에서 우클릭 후 `Git bash here`를 선택하면 해당 폴더 안에서 실행된다.

    ```bash
    git init
    ```

    실행하고 나면 `.git` 폴더가 생성될 것이고, 이를 통해 git이라는 프로그램이 해당 폴더에 대한 기록을 관리한다.

<br>

2.  GitHub 사이트에 접속해서 프로젝트를 올릴 새로운 repository를 만든다.

    1. GitHub에서 오른쪽상단 `+` 버튼 클릭 

    2. `New Repository` 클릭

    3. Repository 이름을 입력하고 `Create repository` 클릭

<br>

3. GitHub Repository와 컴퓨터의 git project를 연결한다.

    1번 과정과 마찬가지로 Terminal에서 프로젝트 폴더로 이동 후 다음과 같은 명령어를 실행한다.

    ```bash
    git remote add origin <repository 주소>
    git branch -M main
    ```

    `repository 주소`는 GitHub Repository에서 사진에서 화살표로 표시된 부분을 클릭하면 복사해 올 수 있다.

    ![1](./1.png)
     
<br>

4. 마지막으로 컴퓨터의 파일들을 github에 올린다.

    ```bash
    git add .
    git commit -m "first commit"
    git push -u origin main
    ```