package TestBoj2533;

import java.util.List;

public class WrongSolution2 implements Solution {

    int N;
    List<List<Integer>> list; //친구들 list
    boolean[] visited; //방문처리
    int ans;

    public WrongSolution2(int N, List<List<Integer>> list) {
        this.N = N;
        this.list = list;
    }

    @Override
    public int answer() {
        ans = 0;
        visited = new boolean[N];

        for (int i = N - 1; i >= 0; i--) {
            if (list.get(i).size() == 1) f(i);
        }
        return ans;
    }

    void f(int i) {
        if (visited[i]) return;

        visited[i] = true;
        int friend = list.get(i).remove(0); //본인리스트에서 친구를 제거 및 반환

        //친구의 방문처리(친구를 얼리어답터로 선택)
        if (!visited[friend]) {
            visited[friend] = true;
            ans++;
        }
        list.get(friend).remove((Integer) i); //친구의 리스트에서 본인을 제거

        //친구의 나머지 친구가 한 명 남았으면 실행
        if (list.get(friend).size() == 1) {
            int friend2 = list.get(friend).remove(0); //친구의 리스트에서 '친구의 친구'를 제거 및 반환
            list.get(friend2).remove((Integer) friend); //'친구의 친구'리스트에서 친구를 제거
            if (list.get(friend2).size() == 1) f(friend2); //'친구의 친구'의 나머지 친구가 한 명 남았으면 friend2를 본인으로 재귀실행
        }
    }
}