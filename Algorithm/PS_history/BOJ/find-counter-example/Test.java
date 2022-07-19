package TestBoj2533;

import java.util.*;

public class Test {

    public static boolean testFor(int N) {
        StringBuilder sb = new StringBuilder();

        List<Integer> visitedNodes = new ArrayList<>();
        List<Integer> unvisitedNodes = new ArrayList<>();
        List<List<Integer>> friends = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            friends.add(new ArrayList<>());
            unvisitedNodes.add(i);
        }

        int root = (int) (Math.random() * N);
        visitedNodes.add(unvisitedNodes.remove(root));
        for (int i = 0; i < N - 1; i++) {
            int node1 = visitedNodes.get((int) (Math.random() * visitedNodes.size()));
            int node2 = unvisitedNodes.remove((int) (Math.random() * unvisitedNodes.size()));
            visitedNodes.add(node2);

            friends.get(node1).add(node2);
            friends.get(node2).add(node1);
            sb.append(String.format("%d %d\n", node1 + 1, node2 + 1));
        }

        Solution rightSolution = new RightSolution(N, friends);
        Solution wrongSolution = new WrongSolution2(N, friends);
        int rightAnswer = rightSolution.answer();
        int wrongAnswer = wrongSolution.answer();

        if (rightAnswer != wrongAnswer) {
            System.out.println("N = " + N);
            System.out.println(sb);
            System.out.println("rightAnswer = " + rightAnswer);
            System.out.println("wrongAnswer = " + wrongAnswer);
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        for (int N = 2; N <= 1000000; N++) {
            long start = System.currentTimeMillis();
            long end = start + 5 * 1000;

            boolean testResult = false;
            while (System.currentTimeMillis() < end) {
                testResult = testFor(N);
                if (testResult) break;
            }
            if (testResult) break;
        }
    }
}
