package TestBoj2533;

import java.util.List;

class RightSolution implements Solution {
    int N;
    List<List<Integer>> friends;
    boolean[] isVisited;
    int[][] dp;

    public RightSolution(int N, List<List<Integer>> friends) {
        this.N = N;
        this.friends = friends;
    }

    @Override
    public int answer() {
        isVisited = new boolean[N];
        dp = new int[N][2];
        dfs(0);
        return Math.min(dp[0][0], dp[0][1]);
    }

    void dfs(int curHuman) {
        isVisited[curHuman] = true;

        dp[curHuman][0] = 0;
        dp[curHuman][1] = 1;

        for (int child : friends.get(curHuman)) {
            if (isVisited[child]) continue;

            dfs(child);
            dp[curHuman][0] += dp[child][1];
            dp[curHuman][1] += Math.min(dp[child][0], dp[child][1]);
        }
    }
}
