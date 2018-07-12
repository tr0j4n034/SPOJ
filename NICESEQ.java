import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        final int MAX_SIZE = 1001;
        final int MODULO = 1000000007;
    
        int dp[][] = new int[MAX_SIZE][];
        for (int i = 0; i < MAX_SIZE; i ++) {
            dp[i] = new int[1 << 10];
        }
        for (int i = 1; i < 10; i ++) {
            dp[1][1 << i] = 1;
        }
        for (int i = 2; i < MAX_SIZE; i ++) {
            for (int j = 1; j < (1 << 10); j ++) {
                int repeating = 0;
                for (int k = 0; k < 10; k ++) {
                    if ((j & (1 << k)) > 0) {
                        if (k != 1) {
                            repeating ++;
                        }
                        if (match(k, j ^ (1 << k))) {
                            dp[i][j] = (dp[i][j] + dp[i - 1][j ^ (1 << k)]) % MODULO;
                        }
                    }
                }
                int extra = (int)(1L * repeating * dp[i - 1][j] % MODULO);
                dp[i][j] = (dp[i][j] + extra) % MODULO;
            }
        }
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int i = 0; i < T; i ++) {
            int N = in.nextInt();
            int result = 0;
            for (int j = 0; j < (1 << 10); j ++) {
                result = (result + dp[N][j]) % MODULO;
            }
            System.out.println(result);
        }
    }
    public static Boolean match(int digit, int mask) {
        if (digit == 0) return true;
        for (int i = 2; i < 10; i ++) {
            if (digit % i == 0 && (mask & (1 << i)) > 0) {
                return true;
            }
        }
        return false;
    }
}
