# Problem G - 스도쿠

## 성공.

예전에 한번 풀어봤던 문제임에도 불구하고,

도중에 구현할 때 실수를 해서 고치느라 시간이 꽤 걸렸다.

<details><summary>소스코드</summary>

```java
import java.io.*;
import java.util.*;

class Main {

    int[][] sudoku = new int[9][9];

    boolean rowCheck(int r) {
        boolean[] checked = new boolean[10];
        for (int i = 0; i < 9; i++) {
            if (sudoku[r][i] == 0) continue;
            if (checked[sudoku[r][i]]) return false;
            checked[sudoku[r][i]] = true;
        }
        return true;
    }

    boolean colCheck(int c) {
        boolean[] checked = new boolean[10];
        for (int i = 0; i < 9; i++) {
            if (sudoku[i][c] == 0) continue;
            if (checked[sudoku[i][c]]) return false;
            checked[sudoku[i][c]] = true;
        }
        return true;
    }

    boolean squareCheck(int r, int c) {
        boolean[] checked = new boolean[10];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int nR = r / 3 * 3 + i;
                int nC = c / 3 * 3 + j;

                if (sudoku[nR][nC] == 0) continue;
                if (checked[sudoku[nR][nC]]) return false;
                checked[sudoku[nR][nC]] = true;
            }
        }
        return true;
    }

    boolean check(int r, int c) {
        if (!rowCheck(r)) return false;
        if (!colCheck(c)) return false;
        if (!squareCheck(r, c)) return false;
        return true;
    }

    boolean complete(int r, int c) {
        if (r == 9) return true;

        int nR = r;
        int nC = c + 1;
        if (nC == 9) {
            nC = 0;
            nR += 1;
        }

        if (sudoku[r][c] != 0) return complete(nR, nC);

        for (int i = 1; i <= 9; i++) {
            sudoku[r][c] = i;
            if (check(r, c)) {
                if (complete(nR, nC)) {
                    return true;
                }
            }
        }
        sudoku[r][c] = 0;
        return false;
    }

    void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int r = 0; r < 9; r++) {
            sudoku[r] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        }

        complete(0, 0);

        for (int r = 0; r < 9; r++) {
            Arrays.stream(sudoku[r]).forEach(a -> System.out.print(a + " "));
            System.out.println();
        }

        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
```

</details>