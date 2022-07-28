# F. 장난감 조립

 ## 성공. 22분

 그래프를 생각한다면 나름 쉽게 구현할 수 있다.

 <details><summary> 소스코드 </summary>
 
 ```java
import java.io.*;
import java.util.*;

class Node {
    public int num, weight;

    public Node(int num, int weight) {
        this.num = num;
        this.weight = weight;
    }
}


class Main {

    int N;
    boolean[] isLeafNode;
    List<List<Node>> childList;
    int[] cnt;

    void f(int product, int num) {
        if (isLeafNode[product]) {
            cnt[product] += num;
            return;
        }

        for (Node child : childList.get(product)) {
            f(child.num, child.weight * num);
        }
    }

    String answer() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N - 1; i++) {
            if(!isLeafNode[i]) continue;
            sb.append(i + 1).append(" ").append(cnt[i]).append("\n");
        }
        return sb.toString();
    }

    void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        isLeafNode = new boolean[N];
        Arrays.fill(isLeafNode, true);
        childList = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            childList.add(new ArrayList<>());
        }
        cnt = new int[N];
        Arrays.fill(cnt, 0);

        int M = Integer.parseInt(br.readLine());
        for (int i = 0; i < M; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int dest = Integer.parseInt(st.nextToken());
            int src = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());
            dest--; src--;
            childList.get(dest).add(new Node(src, weight));
            isLeafNode[dest] = false;
        }

        f(N - 1, 1);
        System.out.print(answer());

        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().run();
    }
}
 ```

 </details>