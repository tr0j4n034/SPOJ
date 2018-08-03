import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int[] data = new int[N + 1];
        int sum = 0;
        for (int i = 1; i <= N; i ++) {
            data[i] = in.nextInt();
            sum += data[i];
        }
        boolean[] can = new boolean[sum + 1];
        can[0] = true;
        for (int i = 1; i <= N; i ++) {
            for (int j = sum - data[i]; j >= 0; j --) {
                can[j + data[i]] |= can[j];
            }
        }
        int best = sum;
        for (int i = sum / 2; i > 0; i --) {
            if (can[i]) {
                best = sum - i * 2;
                break;
            }
        }
        System.out.println(best);
    }
}
