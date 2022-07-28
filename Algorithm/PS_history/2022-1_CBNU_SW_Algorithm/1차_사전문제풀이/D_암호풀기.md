# D. 암호풀기

## 성공. 13분

대소문자랑 공백도 출력해야된다는 조건을 놓쳐서 시간이 좀 걸렸다.

<details><summary>소스코드</summary>

```java
import java.io.*;

class Main {

    char[] key;

    void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        key = br.readLine().toCharArray();
        br.readLine().chars()
                .forEach(word -> {
                    if(Character.isAlphabetic(word))
                        if(Character.isLowerCase(word))
                            System.out.printf("%c", key[word - 'a']);
                        else 
                            System.out.printf("%c", Character.toUpperCase(key[word - 'A']));
                    else 
                        System.out.printf("%c", word);
                });

        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().run();
    }
}
```

</details>