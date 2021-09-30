import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String s = scanner.nextLine();
        char[] str = s.toCharArray();

        int ret = 0;

        for (char c : str) {
            ret += 1;
            switch (c) {
                case 'A':
                case 'B':
                case 'C':
                    ret += 2;
                    break;
                case 'D':
                case 'E':
                case 'F':
                    ret += 3;
                    break;
                case 'G':
                case 'H':
                case 'I':
                    ret += 4;
                    break;
                case 'J':
                case 'K':
                case 'L':
                    ret += 5;
                    break;
                case 'M':
                case 'N':
                case 'O':
                    ret += 6;
                    break;
                case 'P':
                case 'Q':
                case 'R':
                case 'S':
                    ret += 7;
                    break;
                case 'T':
                case 'U':
                case 'V':
                    ret += 8;
                    break;
                case 'W':
                case 'X':
                case 'Y':
                case 'Z':
                    ret += 9;
                    break;
            }
        }

        System.out.println(ret);
        scanner.close();
    }
}