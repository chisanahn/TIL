오픈소스개발프로젝트 때 수정사항이 생길때마다 로컬에서 jar파일 만들고, 이미지로 build해서 dockerhub에 push하고, aws에서 이미지 pull 받고, 컨테이너로 옵션 줘서 run 시키고, 익숙해지니깐 그래도 괜찮았는데 되게 번거로웠다.

aws ec2 용량이 부족해서 docker-compose도 못쓰고..



[패스트캠퍼스 AWS인프라 구축과 DevOps운영](https://fastcampus.co.kr/dev_online_awsdevops?utm_source=kakao&utm_medium=display&utm_campaign=prd210909206717&utm_content=banner1206717)

패스트캠퍼스 광고에서 발견한건데 나중에 `Kubernetes`,  `Kustomize`, `EKS`를 한번 공부해보면 좋을 것 같다.

* `Kubernetes` : 컨테이너화된 애플리케이션의 자동디플로이, 스케일링 등을 제공하는 오픈소스기반 관리시스템이 있었다.
* `Kustomize` : 쿠버네티스 오브젝트를 사용자가 원하는 대로 변경하는 독립형 도구
* `EKS`  : AWS 클라우드 또는 온프레미스에서 Kubernetes 애플리케이션을 시작, 실행 및 조정할 수 있는 유연성을 제공하는 도구



그리고 AWS에 컨테이너 관련 서비스가 있어서 이것도 한번 알아보면 좋을 것 같다.

* `AWS ECR` : 컨테이너 이미지와 아티팩트를 손쉽게 저장, 관리, 공유 및 배포할 수 있는 완전관리형 컨테이너 레지스트리
* `AWS ECS` : 완전 관리형 컨테이너 오케스트레이션 서비스
* `AWS Fargate` : 보안 성능 향상 및 계획적 리소스 관리가 가능한 컨테이너에 적합한 서버리스 컴퓨팅 엔진



그리고 AWS의 경우 공식문서에 튜토리얼이 잘 안내되어있어서 이걸로 공부해봐도 좋을 것 같다.

> AWS에서 메일로 이런저런 자료를 보내주는데 되게 잘 되어있었다.

[AWS 시작하기](https://aws.amazon.com/ko/getting-started/?sc_channel=em&sc_campaign=APAC_field_LN_f30d-notouch-activation_20200713&sc_medium=em_297948&sc_content=adopt_f90d_f90d_field&sc_country=mult&sc_geo=apac&sc_category=mult&sc_outcome=adopt_f90d&trk=em_inv1_zt_kr_a_textlink&mkt_tok=MTEyLVRaTS03NjYAAAGBDOieP2-RpIpUK1f4MNjgQxwzUj4QkkpdDRnVksNmgS7o6Tqo1uHppmuvbQKyxjcY3puik-Lg1_k_kpl5k6lqftKGciJusYxtL89GUuS8ag3Zp7XfbABo#Launch_Your_First_Application)

[AWS에 필요한 실습 자습서 찾기](https://aws.amazon.com/ko/getting-started/hands-on/?getting-started-all.q=10%EB%B6%84&getting-started-all.q_operator=AND&sc_campaign=APAC_field_LN_f30d-notouch-activation_20200713&sc_medium=em_297948&sc_content=adopt_f90d_f90d_field&sc_country=mult&sc_geo=apac&sc_category=mult&sc_outcome=adopt_f90d&trk=em_inv2_zt_kr_a_textlink&mkt_tok=MTEyLVRaTS03NjYAAAGBHJALiuYqCyC3uAy2egW6O27twQlVHfb3zw1sYolJu9CkDUyZvVD4FvJK4EO6S7SJ2hRniiJXRnuS2Zx2mhddczI2ZQBvxyznRFmir84E0CdppzbWrT2c&awsf.getting-started-category=*all&awsf.getting-started-level=*all&awsf.getting-started-content-type=*all)



CI/CD의 경우 블로그에서 Jenkins 예제 정도만 봤었는데 이용할 수 있는 서비스가 굉장히 많아서 한번 알아보면 좋을 것 같다.

* AWS CodeBuild
* AWS CodeCommit
* AWS CodeDeploy
* AWS CodePieline
* Github Action
* Jenkins
* Circle CI
* ArgoCD



