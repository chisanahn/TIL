import java.io.*;
import java.util.*;

class RightSolution {

    public RightSolution(int n, int k, long[] a) {
        N = n;
        this.k = k;
        A = a;

        solution();
    }

    int N, k;
    long[] A;

    long cnt, cost;

    int left() {
        for (int i = 0; i < N; i++) {
            if (A[i] > 0) return i;
        }
        return -1;
    }

    int right() {
        for (int i = N - 1; i >= 0; i--) {
            if (A[i] > 0) return i;
        }
        return -1;
    }

    void solution() {
        A = Arrays.stream(A).map(a -> (k > a) ? k - a : 0).toArray();

        cnt = 0;
        cost = 0;

        for (cnt = 0; ; cnt++) {
            int left = left();
            int right = right();
            if (left == -1 || right == -1) break;

            for (int i = left; i <= right; i++) {
                A[i]--;
                cost++;
            }
        }
    }

    @Override
    public String toString() {
        return "RightSolution{" +
                "cnt=" + cnt +
                ", cost=" + cost +
                '}';
    }
}