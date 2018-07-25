import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int low = in.nextInt();
        int high = in.nextInt();
        long result = 0;
        while (high > low && !isPrime(high)) {
            result += high;
            high --;
        }
        if (high > low) {
            result += high;
        }
        System.out.println(result);
    }
    public static Boolean isPrime(int N) {
        if (N < 2) return false;
        for (int i = 2; i * i <= N; i ++) {
            if (N % i == 0) {
                return false;
            }
        }
        return true;
    }
}
