import java.math.BigInteger;
import java.util.Scanner;
 
public class Main{ 
 
    public static void main(String[]  args) {
       Scanner in = new Scanner(System.in);
       while(in.hasNextBigInteger()){
           BigInteger x = in.nextBigInteger();
           BigInteger one = new BigInteger("1");
           if(x.compareTo(one) == 0){
               System.out.println(x);
           }
           else{
               System.out.println(x.add(x.subtract(new BigInteger("2"))));
           }
       }
    }
}