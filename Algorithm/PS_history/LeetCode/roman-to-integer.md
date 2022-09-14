# 13. Roman to Integer

Easy

https://leetcode.com/problems/roman-to-integer/submissions/

<br>

## 성공

<details><summary>소스코드</summary>

```java
import java.util.*;

class Solution {

    HashMap<Character, Integer> romanToInteger = new HashMap<>();

    public int romanToInt(String s) {

        romanToInteger = new HashMap<>();
        romanToInteger.put('I', 1);
        romanToInteger.put('V', 5);
        romanToInteger.put('X', 10);
        romanToInteger.put('L', 50);
        romanToInteger.put('C', 100);
        romanToInteger.put('D', 500);
        romanToInteger.put('M', 1000);

        int result = 0;
        for (int i = 0; i < s.length(); i++) {

            int curNum = romanToInteger.get(s.charAt(i));
            result += curNum;

            if (i == s.length() - 1) return result;

            String curNumString = Integer.toString(curNum);
            if (curNumString.charAt(0) == '1') {
                int nextNum = romanToInteger.get(s.charAt(i + 1));
                String nextNumString = Integer.toString(nextNum);

                if ((curNumString.length() == nextNumString.length() && nextNumString.charAt(0) == '5')
                        || (curNumString.length() + 1 == nextNumString.length() && nextNumString.charAt(0) == '1')) {
                    result += (nextNum - curNum * 2);
                    i++;
                }
            }
        }
        return result;
    }
}
```

</details>