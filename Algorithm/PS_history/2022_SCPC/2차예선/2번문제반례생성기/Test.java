import java.util.Arrays;

public class Test {
    public static void main(String[] args) {
        while (true) {
//            int N = 3;
//            int k = (int)(Math.random()*100) + 1;
//            long[] A = new long[N];
//            for (int i = 0; i < N; i++) {
//                A[i] = (long)(Math.random()*10000);
//            }
            int N = 3;
            int k = 93;
            long[] A = {8, 7414, 2282};

            RightSolution rs = new RightSolution(N, k, A);
            WrongSolution ws = new WrongSolution(N, k, A);

            if(rs.cnt != ws.cnt || rs.cost != ws.cost) {
                System.out.println("N = " + N);
                System.out.println("k = " + k);
                Arrays.stream(A).forEach(a -> System.out.print(a + " "));
                System.out.println();

                System.out.println(rs);
                System.out.println(ws);
                break;
            }
        }
    }
}
