// Codeforces Round #747 (Div. 2), problem: (A) Consecutive Sum Riddle, Accepted
// Java 11	217 ms	23400 KB

import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer in = new StringTokenizer(br.readLine());
        PrintWriter out = new PrintWriter(System.out);
 
        int n = Integer.parseInt(in.nextToken());
        for(int i = 0; i < n; i++) {
            in = new StringTokenizer(br.readLine());
            long inpt = Long.parseLong(in.nextToken());
            out.println(-(inpt - 1) + " " + inpt);
        }
 
        out.close();
    }
}
