package TestBoj2533;

import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

class Human implements Comparable<Human> {
    public int num, friendsCnt;

    public Human(int num, int friendsCnt) {
        this.num = num;
        this.friendsCnt = friendsCnt;
    }

    @Override
    public int compareTo(Human o) {
        return o.friendsCnt - this.friendsCnt;
    }
}

public class WrongSolution implements Solution {

    int N;
    List<List<Integer>> friends;
    int[] updateCnt;
    boolean[] isEarlyAdopter;
    PriorityQueue<Human> pq;

    public WrongSolution(int N, List<List<Integer>> friends) {
        this.N = N;
        this.friends = friends;
        updateCnt = new int[N];
        isEarlyAdopter = new boolean[N];
    }

    @Override
    public int answer() {
        Arrays.fill(updateCnt, 0);
        Arrays.fill(isEarlyAdopter, false);
        pq = new PriorityQueue<>();
        for (int i = 0; i < N; i++) {
            pq.add(new Human(i, friends.get(i).size()));
        }
        return f();
    }

    int f() {
        int earlyAdopterCnt = 0;

        while (!pq.isEmpty()) {
            Human earlyAdopterCandidate = pq.poll();
            if (earlyAdopterCandidate.friendsCnt == 0) break;

            if (isEarlyAdopter[earlyAdopterCandidate.num]) continue;

            if (updateCnt[earlyAdopterCandidate.num] > 0) {
                pq.add(new Human(earlyAdopterCandidate.num, earlyAdopterCandidate.friendsCnt - updateCnt[earlyAdopterCandidate.num]));
                updateCnt[earlyAdopterCandidate.num] = 0;
                continue;
            }

            isEarlyAdopter[earlyAdopterCandidate.num] = true;
            earlyAdopterCnt++;
            for (int friend : friends.get(earlyAdopterCandidate.num)) {
                updateCnt[friend]++;
            }
        }
        return earlyAdopterCnt;
    }
}