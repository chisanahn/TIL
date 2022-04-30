웹소프트웨어과제로 JSP 개발을 하다가 예외처리를 하려고 처음 사용자 정의 예외를 만들고 `throws`를 사용해서 예외 처리를 해줬는데  예외처리가 안되고 이상하게 서버 로그에만 예외가 찍히길래 JSP에 문제가 있는건가 싶었는데 알고보니 throws를 던져주는 메서드 내부에서 try-catch 구문으로 예외를 `printStackTrace()`로 다 처리하고 있었다.

```java
public void login(String memberId, String memberPassword) throws Exception {
    String SQL = "SELECT password FROM member WHERE id = ?";
    try {
        pstmt = conn.prepareStatement(SQL);
        pstmt.setString(1, memberId);
        System.out.println("memberId = " + memberId + ", memberPassword = " + memberPassword);
        rs = pstmt.executeQuery();
        if (rs.next()) {
            if (rs.getString(1).equals(memberPassword)) {
                return;
            } else {
                throw new WrongPasswordException();
            }
        }
        throw new NotExistMemberException();
    } catch (Exception e) {
        e.printStackTrace();
    }
}
```