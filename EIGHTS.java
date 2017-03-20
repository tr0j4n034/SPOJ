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
        
        /*
        for(int i = 2; i < 10000; i ++){
            Long cube = 1L * i * i * i;
            if(cube % 1000 == 888){
                System.out.println(i + " " + cube);
            }
        }
        */
        int t;
        Long n;
        t = in.nextInt();
        while(t > 0){
            n = in.nextLong();
            System.out.println(n * 250 - 58);
            t--;
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
        public Long nextLong() {
            return Long.parseLong(next());
        }
    }
}
