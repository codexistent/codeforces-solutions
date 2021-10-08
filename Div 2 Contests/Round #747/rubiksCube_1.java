// Codeforces Round #747 (Div. 2), problem: (E1) Rubik's Cube Coloring (easy version), Accepted
// Java 11	217 ms	23400 KB

import java.io.*;
import java.util.*;
 
public class Main {
    static long CONSTANT = (long) Math.pow(10l, 9) + 7;
 
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer in = new StringTokenizer(br.readLine());
        PrintWriter out = new PrintWriter(System.out);
 
        int n = Integer.parseInt(in.nextToken());
        long ans = 6;
        long toMultiply = 16;
 
        for(int i = 1; i < n; i++) {
            ans = ((ans * toMultiply) % CONSTANT);
            toMultiply = (toMultiply * toMultiply) % CONSTANT;
        }
        
        out.println(ans);
        out.close();
    }
}
