import java.util.*;

class Main {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        int count[] = new int[10];
        for (int i=0; i<10; i++) {
            count[i] = 0;
        }

        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();
        
        int ret = A*B*C;
        while(ret > 0) {
            count[ret%10]++;
            ret/=10;
        }

        for(int c : count) System.out.println(c);
    }
}