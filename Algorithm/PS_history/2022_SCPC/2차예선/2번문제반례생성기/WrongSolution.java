import java.io.*;
import java.util.*;

public class WrongSolution {

    int N, k;
    long[] A;

    public WrongSolution(int n, int k, long[] a) {
        N = n;
        this.k = k;
        A = a;

        solution();
    }

    long cnt, cost;

    int nextLeft(int idx) {
        for (int i = idx + 1; i < N; i++) {
            if (A[i] > A[idx]) return i;
        }
        return -1;
    }

    int nextRight(int idx) {
        for (int i = idx - 1; i >= 0; i--) {
            if (A[i] > A[idx]) return i;
        }
        return -1;
    }

    void solution() {

        A = Arrays.stream(A).map(a -> (k > a) ? k - a : 0).toArray();

        cnt = 0;
        cost = 0;

        int left = (A[0] == 0) ? nextLeft(0) : 0;
        int right = (A[N - 1] == 0) ? nextRight(N - 1) : N - 1;
        long prevHeight = 0;
        long curHeight = 0;

        while (left != -1 && right != -1) {
            curHeight = Math.min(A[left], A[right]);
            cnt += (curHeight - prevHeight);
            cost += (right - left + 1) * (curHeight - prevHeight);

            if (A[left] < A[right]) left = nextLeft(left);
            else if (A[left] > A[right]) right = nextRight(right);
            else {
                left = nextLeft(left);
                right = nextRight(right);
            }
            prevHeight = curHeight;
        }
    }

    @Override
    public String toString() {
        return "WrongSolution{" +
                "cnt=" + cnt +
                ", cost=" + cost +
                '}';
    }
}

