package soli;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Soli{ 
 
    public static void main(String[]  args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        
        
        int n;
        while(true){
            n = in.nextInt();
            if(n == 0)
                break;
            
            int []a = new int [n];
            int []b = new int [n];
            for(int i = 0; i < n; i ++)
                a[i] = in.nextInt();
            for(int i = 0; i < n; i ++)
                b[i] = in.nextInt();
            Arrays.sort(a);
            Arrays.sort(b);
            
            long ans = 0;
            for(int i = 0; i < n; i ++)
                ans += 1L * a[i] * b[n - 1 - i];
            System.out.println(ans);
        }
    }
    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}
