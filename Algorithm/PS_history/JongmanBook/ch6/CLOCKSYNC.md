# 시계 맞추기

- ch6. 무식하게 풀기
- 난이도 : 중

https://algospot.com/judge/problem/read/CLOCKSYNC

<br>

## 실패. 규칙 찾아서 구현

시계마다 관련된 스위치를 나열하니깐 순서가 나왔다.

1. 시계 12, 8은 4번 스위치랑만 연결되어 있기 때문에 4번 스위치의 횟수는 이 2개의 시계에 의해서 결정된다.

2. 그리고 시계 10의 경우, 4번 스위치와 2번 스위치랑만 연결되어 있고, 4번 스위치는 시계 12와 8에 의해서 유일하게 결정된다.

    따라서 2번 스위치의 횟수는 시계 10에 의해서 유일하게 결정된다.

3. ....

이런 식으로 쭉 구할 수 있다.

> 구현하는데 1시간 정도 소요.
>
> 예제도 잘나왔지만 제출해보니 오답이 나왔다.

<details><summary>소스코드</summary>

```java
import java.io.*;
import java.util.*;

class Main {

    final int NUM_OF_BUTTON = 10;
    final int NUM_OF_CLOCK = 16;

    final int[] searchOrder = {12, 8, 11, 13, 9, 10, 6, 7, 5, 4, 1, 2, 3, 14, 15, 0};

    int[] time;
    boolean[] isChecked;
    int[] buttonCnt;

    int[][] clocksForButton = {
            {0, 1, 2},
            {3, 7, 9, 11},
            {4, 10, 14, 15},
            {0, 4, 5, 6, 7},
            {6, 7, 8, 10, 12},
            {0, 2, 14, 15},
            {3, 14, 15},
            {4, 5, 7, 14, 15},
            {1, 2, 3, 4, 5},
            {3, 4, 5, 9, 13}
    };
    List<List<Integer>> buttonsForClock;

    int f() {
        int ret = 0;
        for (int curClock : searchOrder) {
            int totalCnt = 0;
            int unCheckedBtnCnt = 0;
            for (int button : buttonsForClock.get(curClock)) {
                if(!isChecked[button]) {
                    unCheckedBtnCnt++;
                    continue;
                }
                totalCnt += buttonCnt[button];
            }

            int curTime = (time[curClock] + totalCnt) % 4;
            int leftCnt = (4 - curTime) % 4;
            ret += leftCnt;

            for (int button : buttonsForClock.get(curClock)) {
                if(isChecked[button]) continue;
                isChecked[button] = true;
                buttonCnt[button] = leftCnt;
                curTime = (curTime + leftCnt) % 4;
                break;
            }
            if(curTime != 0) return -1;
        }
        return ret;
    }

    void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine().trim());
        for (int test = 0; test < T; test++) {
            
            time = Arrays.stream(br.readLine().trim().split(" "))
                    .mapToInt(Integer::parseInt).map(a -> a / 3 % 4).toArray();
            
            buttonCnt = new int[NUM_OF_BUTTON];
            Arrays.fill(buttonCnt, 0);
            
            buttonsForClock = new ArrayList<>();
            for (int i = 0; i < NUM_OF_CLOCK; i++) {
                buttonsForClock.add(new ArrayList<>());
            }
            for (int button = 0; button < NUM_OF_BUTTON; button++) {
                for (int clock : clocksForButton[button]) {
                    buttonsForClock.get(clock).add(button);
                }
            }
            
            isChecked = new boolean[NUM_OF_BUTTON];
            Arrays.fill(isChecked, false);

            int answer = f();
            sb.append(answer).append("\n");
        }
        System.out.print(sb.toString());

        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().run();
    }
}
```

</details>

<br>

## 완탐으로 성공

어차피 각 스위치는 0, 1, 2, 3번 누르는 경우, 총 4가지 경우의 수가 존재하고, 스위치는 총 10개 있으므로

고려해야하는 경우의 수 4^10, 약 10^6이므로 충분히 제한 시간 안에 구할 수 있다.

<details><summary>소스코드</summary>

```java
import java.io.*;
import java.util.*;

class Main {

    final int INF = 987654321;

    final int NUM_OF_BUTTON = 10;
    final int NUM_OF_CLOCK = 16;

    final int[] searchOrder = {12, 8, 11, 13, 9, 10, 6, 7, 5, 4, 1, 2, 3};

    int[] timeOfClocks;
    boolean[] isChecked;
    int[] buttonCnt;

    int[][] clocksForButton = {
            {0, 1, 2},
            {3, 7, 9, 11},
            {4, 10, 14, 15},
            {0, 4, 5, 6, 7},
            {6, 7, 8, 10, 12},
            {0, 2, 14, 15},
            {3, 14, 15},
            {4, 5, 7, 14, 15},
            {1, 2, 3, 4, 5},
            {3, 4, 5, 9, 13}
    };
    List<List<Integer>> buttonsForClock;

    int answer;

    boolean check() {
        int[] changedTimeOfClocks = new int[NUM_OF_CLOCK];
        for (int i = 0; i < NUM_OF_CLOCK; i++) {
            changedTimeOfClocks[i] = timeOfClocks[i];
        }

        for (int button = 0; button < NUM_OF_BUTTON; button++) {
            for (int clock : clocksForButton[button]) {
                changedTimeOfClocks[clock] = (changedTimeOfClocks[clock] + buttonCnt[button]) % 4;
            }
        }

        for (int changedTime : changedTimeOfClocks) {
            if (changedTime != 0) return false;
        }
        return true;
    }

    void f(int idx) {
        if (idx == NUM_OF_BUTTON) {
            if (!check()) return;

            int totalCnt = 0;
            for (int cnt : buttonCnt) {
                totalCnt += cnt;
            }
            answer = Math.min(answer, totalCnt);
            return;
        }

        for (int cnt = 0; cnt < 4; cnt++) {
            buttonCnt[idx] = cnt;
            f(idx + 1);
        }
    }

    void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine().trim());
        for (int test = 0; test < T; test++) {

            timeOfClocks = Arrays.stream(br.readLine().trim().split(" "))
                    .mapToInt(Integer::parseInt).map(a -> a / 3 % 4).toArray();

            buttonCnt = new int[NUM_OF_BUTTON];
            Arrays.fill(buttonCnt, 0);

            buttonsForClock = new ArrayList<>();
            for (int i = 0; i < NUM_OF_CLOCK; i++) {
                buttonsForClock.add(new ArrayList<>());
            }
            for (int button = 0; button < NUM_OF_BUTTON; button++) {
                for (int clock : clocksForButton[button]) {
                    buttonsForClock.get(clock).add(button);
                }
            }

            isChecked = new boolean[NUM_OF_BUTTON];
            Arrays.fill(isChecked, false);

            answer = INF;
            f(0);

            if(answer == INF) sb.append(-1).append("\n");
            else sb.append(answer).append("\n");
        }
        System.out.print(sb.toString());

        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().run();
    }
}
```

</details>

<br>

## 성공. 규칙 찾는 방식

완탐으로 성공 후 코드를 다시 봤더니 탐색 순서에 14, 15, 0을 빠트렸었다.

> ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ

<details><summary>소스코드</summary>

```java
import java.io.*;
import java.util.*;

class Main {

    final int NUM_OF_BUTTON = 10;
    final int NUM_OF_CLOCK = 16;

    final int[] searchOrder = {12, 8, 11, 13, 9, 10, 6, 7, 5, 4, 1, 2, 3, 14, 15, 0};

    int[] time;
    boolean[] isChecked;
    int[] buttonCnt;

    int[][] clocksForButton = {
            {0, 1, 2},
            {3, 7, 9, 11},
            {4, 10, 14, 15},
            {0, 4, 5, 6, 7},
            {6, 7, 8, 10, 12},
            {0, 2, 14, 15},
            {3, 14, 15},
            {4, 5, 7, 14, 15},
            {1, 2, 3, 4, 5},
            {3, 4, 5, 9, 13}
    };
    List<List<Integer>> buttonsForClock;

    int f() {
        int ret = 0;
        for (int curClock : searchOrder) {
            int totalCnt = 0;
            for (int button : buttonsForClock.get(curClock)) {
                if(!isChecked[button]) continue;
                
                totalCnt += buttonCnt[button];
            }

            int curTime = (time[curClock] + totalCnt) % 4;
            int leftCnt = (4 - curTime) % 4;
            ret += leftCnt;

            for (int button : buttonsForClock.get(curClock)) {
                if(isChecked[button]) continue;
                isChecked[button] = true;
                buttonCnt[button] = leftCnt;
                curTime = (curTime + leftCnt) % 4;
                break;
            }
            if(curTime != 0) return -1;
        }
        return ret;
    }

    void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine().trim());
        for (int test = 0; test < T; test++) {

            time = Arrays.stream(br.readLine().trim().split(" "))
                    .mapToInt(Integer::parseInt).map(a -> a / 3 % 4).toArray();

            buttonCnt = new int[NUM_OF_BUTTON];

            buttonsForClock = new ArrayList<>();
            for (int i = 0; i < NUM_OF_CLOCK; i++) {
                buttonsForClock.add(new ArrayList<>());
            }
            for (int button = 0; button < NUM_OF_BUTTON; button++) {
                for (int clock : clocksForButton[button]) {
                    buttonsForClock.get(clock).add(button);
                }
            }

            isChecked = new boolean[NUM_OF_BUTTON];

            int answer = f();
            sb.append(answer).append("\n");
        }
        System.out.print(sb.toString());

        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().run();
    }
}

```

</details>