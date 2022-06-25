# D. Vertical Paths

처음에는 간단한 그래프 탐색 문제인줄 알았는데

루트노트부터 시작해서 탐색해가면서 경로의 시작점들을 미리 저장해두어야 한다.

<details><summary>test4에서 시간초과</summary>

```java
import java.io.*;
import java.util.*;

public class Main {

    int numOfVerticesOfTree;
    int[] parentOfVertexes;
    List<List<Integer>> childOfVertexes;

    void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numberOfTest = Integer.parseInt(br.readLine());
        for (int test = 0; test < numberOfTest; test++) {
            numOfVerticesOfTree = Integer.parseInt(br.readLine());
            childOfVertexes = new ArrayList<>();
            for (int i = 0; i <= numOfVerticesOfTree; i++) {
                childOfVertexes.add(new ArrayList<>());
            }
            parentOfVertexes = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

            // 그래프 생성
            int rootNode = 0;
            for (int i = 0; i < parentOfVertexes.length; i++) {
                int curVertex = i + 1;
                int parentVertex = parentOfVertexes[i];

                // root 노드 에외처리
                if (curVertex == parentVertex) {
                    rootNode = curVertex;
                } else {
                    childOfVertexes.get(parentVertex).add(curVertex);
                }
            }

            List<Queue<Integer>> paths = new ArrayList<>();

            Queue<Integer> startNodes = new LinkedList<>();
            startNodes.add(rootNode);
            while (!startNodes.isEmpty()) {
                int curNode = startNodes.poll();
                Queue<Integer> curPath = new LinkedList<>();
                while (true) {
                    curPath.add(curNode);
                    List<Integer> childOfVertex = childOfVertexes.get(curNode);

                    if (childOfVertex.size() == 0) {
                        paths.add(curPath);
                        break;
                    }

                    curNode = childOfVertex.get(0);
                    for (int i = 1; i < childOfVertex.size(); i++) {
                        startNodes.add(childOfVertex.get(i));
                    }
                }
            }
            System.out.println(paths.size());

            for (Queue<Integer> curPath : paths) {
                System.out.println(curPath.size());
                while (!curPath.isEmpty()) {
                    System.out.print(curPath.poll() + " ");
                }
                System.out.println();
            }
            System.out.println();
        }
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
```

</details>

## 성공. 50분 정도 소요

로직 자체는 더 이상 시간 최적화를 할 수가 없을 것 같아서

출력량이 많아서 시간초과가 된건가 싶어서 BufferedWriter를 사용해봤더니 AC를 받았다.

```java
import java.io.*;
import java.util.*;

public class Main {

    int numOfVerticesOfTree;
    int[] parentOfVertexes;
    List<List<Integer>> childOfVertexes;

    void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int numberOfTest = Integer.parseInt(br.readLine());
        for (int test = 0; test < numberOfTest; test++) {
            numOfVerticesOfTree = Integer.parseInt(br.readLine());
            childOfVertexes = new ArrayList<>();
            for (int i = 0; i <= numOfVerticesOfTree; i++) {
                childOfVertexes.add(new ArrayList<>());
            }
            parentOfVertexes = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

            // 그래프 생성
            int rootNode = 0;
            for (int i = 0; i < parentOfVertexes.length; i++) {
                int curVertex = i + 1;
                int parentVertex = parentOfVertexes[i];

                // root 노드 에외처리
                if (curVertex == parentVertex) {
                    rootNode = curVertex;
                } else {
                    childOfVertexes.get(parentVertex).add(curVertex);
                }
            }

            List<Queue<Integer>> paths = new ArrayList<>();

            Queue<Integer> startNodes = new LinkedList<>();
            startNodes.add(rootNode);
            while (!startNodes.isEmpty()) {
                int curNode = startNodes.poll();
                Queue<Integer> curPath = new LinkedList<>();
                while (true) {
                    curPath.add(curNode);
                    List<Integer> childOfVertex = childOfVertexes.get(curNode);

                    if (childOfVertex.size() == 0) {
                        paths.add(curPath);
                        break;
                    }

                    curNode = childOfVertex.get(0);
                    for (int i = 1; i < childOfVertex.size(); i++) {
                        startNodes.add(childOfVertex.get(i));
                    }
                }
            }
            bw.write(Integer.toString(paths.size()) + "\n");

            for (Queue<Integer> curPath : paths) {
                bw.write(Integer.toString(curPath.size()) + "\n");
                while (!curPath.isEmpty()) {
                    bw.write(Integer.toString(curPath.poll()) + " ");
                }
                bw.write('\n');
            }
            bw.write('\n');
        }

        br.close();
        bw.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
```

