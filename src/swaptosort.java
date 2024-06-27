import java.io.*;
import java.util.*;

class Solution {
    static PrintStream p = System.out;

    public static void main(String[] args) throws IOException {
        class UFDS {
            int[] p;
            UFDS(int n) {
                this.p = new int[n + 1];
                for (int i = 1; i <= n; i++) {
                    p[i] = i;
                }
            }
            int findSet(int n) {
                if (p[n] == n) {
                    return n;
                }
                p[n] = findSet(p[n]);
                return p[n];
            }
            void union(int x, int y) {
                p[findSet(x)] = findSet(y);
            }
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        String[] temp = br.readLine().split(" ");
        int n = Integer.parseInt(temp[0]);
        UFDS ufds = new UFDS(n);
        int k = Integer.parseInt(temp[1]);
        for (int i = 0; i < k; i++) {
            temp = br.readLine().split(" ");
            ufds.union(Integer.parseInt(temp[0]), Integer.parseInt(temp[1]));
        }
        for (int i = 1; i <= n / 2; i++) {
            if (ufds.findSet(i) != ufds.findSet(n + 1 - i)) {
                pw.println("No");
                pw.close();
                return;
            }
        }
        pw.println("Yes");
        pw.close();
    }
}