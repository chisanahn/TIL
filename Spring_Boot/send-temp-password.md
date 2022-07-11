# 임시 비밀번호 생성해서 메일로 보내주기

이번에 비밀번호를 잊어버렸을때 메일을 통해 복구하는 기능을 구현하면서 알게된 내용 정리

<br>

## Java Mail Sender

https://victorydntmd.tistory.com/342

Spring에서 지원해주는 이메일 전송 시스템

<br>

## gmail 계정으로 SMTP 서버 사용하는 방법

https://yermi.tistory.com/346

- `gmail 환경설정` -> `모든 설정` -> `전달 및 POP/IMAP` -> `IMAP 사용` -> `변경사항 저장`

- 비밀번호를 그냥 사용할 경우 인증 오류가 발생하므로, 2차 인증 설정 후 앱 비밀번호를 만들어서 사용해야 한다.

  > gmail 설정에서 보안 수준이 낮은 앱 허용 설정을 해주는 방식도 있지만 권장되지 않는다.

<br>

## SecureRandom

`Random` class의 보얀 취약점을 개선한 클래스

https://moonsiri.tistory.com/39