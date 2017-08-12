import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        while (T-- > 0) {
            int a = in.nextInt();
            int b = in.nextInt();
            BigInteger m = in.nextBigInteger();
            System.out.println(power(a, b, m));
        }
    }
    static BigInteger power(int a, int b, BigInteger m) {
        if (b == 0) {
            return BigInteger.ONE.mod(m);
        }
        BigInteger halfPower = power(a, b >> 1, m);
        halfPower = halfPower.multiply(halfPower);
        if (b % 2 == 1) {
            halfPower = halfPower.multiply(BigInteger.valueOf(a));
        }
        return halfPower.mod(m);
    }
    
}
