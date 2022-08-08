# Problem A - 회의실 배정

<br>

<details><summary>소스코드</summary>

```java
import java.util.*;
import java.io.*;

public class Main {

    class Meeting implements Comparable<Meeting> {
        public int num, startTime, endTime;

        public Meeting(int num, int startTime, int endTime) {
            this.num = num;
            this.startTime = startTime;
            this.endTime = endTime;
        }

        @Override
        public int compareTo(Meeting o) {
            return this.endTime - o.endTime;
        }
    }

    int N;

    void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        N = Integer.parseInt(br.readLine());
        PriorityQueue<Meeting> pq = new PriorityQueue<>();
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken());
            int startTime = Integer.parseInt(st.nextToken());
            int endTime = Integer.parseInt(st.nextToken());
            pq.add(new Meeting(num, startTime, endTime));
        }

        Queue<Integer> answer = new LinkedList<>();
        int curEndTime = 0;
        while (!pq.isEmpty()) {
            Meeting curMeeting = pq.poll();
            while (!pq.isEmpty() && curMeeting.startTime < curEndTime) {
                curMeeting = pq.poll();
            }
            answer.add(curMeeting.num);
            curEndTime = curMeeting.endTime;
        }

        sb.append(answer.size()).append("\n");
        while (!answer.isEmpty()) {
            sb.append(answer.poll()).append(" ");
        }
        System.out.println(sb.toString());

        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
```

</details>

## 실패

간단한 그리디 문제인데 구현 실수를 해서 엄청 헤맸다

> 왠만한 반례도 다 통과해버려서, 인터넷에서 정답 풀이를 보고서도 한참 헤맸다. 

<details><summary>수정 후 소스코드</summary>

```java
import java.util.*;
import java.io.*;

public class Main {

    class Meeting implements Comparable<Meeting> {
        public int num, startTime, endTime;

        public Meeting(int num, int startTime, int endTime) {
            this.num = num;
            this.startTime = startTime;
            this.endTime = endTime;
        }

        @Override
        public int compareTo(Meeting o) {
            return this.endTime - o.endTime;
        }
    }

    int N;

    void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        N = Integer.parseInt(br.readLine());
        PriorityQueue<Meeting> pq = new PriorityQueue<>();
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken());
            int startTime = Integer.parseInt(st.nextToken());
            int endTime = Integer.parseInt(st.nextToken());
            pq.add(new Meeting(num, startTime, endTime));
        }

        Queue<Integer> answer = new LinkedList<>();
        int curMeetingEndTime = 0;
        while (!pq.isEmpty()) {
            Meeting nextMeeting = pq.poll();
            if (nextMeeting.startTime < curMeetingEndTime) continue;

            answer.add(nextMeeting.num);
            curMeetingEndTime = nextMeeting.endTime;
        }

        sb.append(answer.size()).append("\n");
        while (!answer.isEmpty()) {
            sb.append(answer.poll()).append(" ");
        }
        System.out.println(sb.toString());

        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
```

</details>