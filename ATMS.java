import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import java.awt.Rectangle;

public class Main {

    public static void main( String[] args ) {
        
        InputStream inputStream = System.in ;
        InputReader in = new InputReader( inputStream ) ;
        Solution solver = new Solution();
        solver.solve( in ) ;

    }

}

class cmp implements Comparator<Integer> {

    public int compare( Integer a, Integer b ) {

        return b.compareTo( a ) ;
    }
}

class Solution{

    boolean time = false ;
    int i, Pos ;
    boolean flag ;
    BigInteger n, r ;
    int p[] = new int[111] ;
    BigInteger B = new BigInteger("-2") ;
    void solve( InputReader in ) {
        
        try{
            
            long start=System.currentTimeMillis();
            
            int t ;
            t = in.nextInt() ;
            while( t-- > 0 ) {
                n = in.nextBigInteger() ;
                Calc(n) ;
                Calc( BigInteger.ZERO.subtract( n ) ) ;
            }
            
            long end=System.currentTimeMillis();
            if(time)
                System.out.println("Execution time: "+(double)(end-start)/1000.0);
        }
        catch(Exception e){
            System.out.println("Error: "+e);
        };
    }
    void Calc( BigInteger n ) {
        Pos = 0 ;
        flag = true ;
        for( i = 0 ; i < 100; ++i ) 
            p[i] = 0 ;
        while( true ) {
            if( n.compareTo(BigInteger.ZERO) == 0 ) 
                break ;
            if( Pos == 100 ) {
                System.out.println("No") ;
                flag = false ;
                break ;
            } 
            r = n.remainder( B ) ;
            n = n.divide( B ) ;
            if( r.compareTo( BigInteger.ZERO ) == 0 )
                p[Pos] = 0 ; 
            else {
                p[Pos] = 1 ;
                if( r.compareTo( BigInteger.ZERO) < 0 )
                    n = n.add( BigInteger.ONE ) ;
            }
            ++Pos ;
        }
        if( flag ) {
            flag = false ;
            for( i = 99; i >= 0; --i ) {
                if( p[i] == 1 ) {
                    if( flag ) 
                        System.out.print(' ') ;
                    System.out.print( i ) ;
                    flag = true ;
                }
            }
            System.out.println() ;
        }
    }
}

class InputReader {

    public BufferedReader reader ;
    public StringTokenizer tokenizer ;
    
    public InputReader( InputStream stream ) {
        reader = new BufferedReader( new InputStreamReader( stream ) ) ;
        tokenizer = null ;
    }
    public String next() {
        while( tokenizer == null || !tokenizer.hasMoreTokens() ) {
            try{
                tokenizer = new StringTokenizer( reader.readLine() ) ;
            }catch( IOException e ) {
                throw new RuntimeException( e ) ;
            }
        }
        return tokenizer.nextToken() ;
    }
    public int nextInt() {
        return Integer.parseInt( next() ) ;
    }
    public long nextLong() {
        return Long.parseLong( next() ) ;
    }
    public BigInteger nextBigInteger() {
        return new BigInteger( next() ) ;
    }
    public String nextString() {
        return String.valueOf( next() ) ;
    }
}  