import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int i = 0; i < T; i ++) {
            int a = in.nextInt();
            int b = in.nextInt();
            int c = in.nextInt();
            System.out.print("Case " + Integer.toString(i + 1) + ": ");
            if (c < 1 || a - b != c) {
                System.out.println("NO");
            } else {
                System.out.println("YES");
            }
        }
    }
}

