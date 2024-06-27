import java.io.*;
import java.util.*;

class Solution {
    static PrintStream p = System.out;

    public static void main(String[] args) throws IOException {
        class UFDS {
            int[] p;
            int[] size;
            UFDS(int n) {
                this.p = new int[n + 1];
                for (int i = 1; i <= n; i++) {
                    p[i] = i;
                }
                this.size = new int[n + 1];
                Arrays.fill(size, 1);
            }
            int findSet(int n) {
                if (p[n] == n) {
                    return n;
                }
                p[n] = findSet(p[n]);
                return p[n];
            }
            void union(int x, int y) {
                x = findSet(x);
                y = findSet(y);
                if (x != y) {
                    p[x] = y;
                    size[y] += size[x];
                }
            }
            int size(int n) {
                return size[findSet(n)];
            }
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        String[] temp = br.readLine().split(" ");
        int n = Integer.parseInt(temp[0]);
        for (int i = 0; i < n; i++) {
            int f = Integer.parseInt(br.readLine());
            UFDS ufds = new UFDS(f * 2);
            HashMap<String,Integer> map = new HashMap<>();
            int num = 1;
            for (int j = 0; j < f; j++) {
                temp = br.readLine().split(" ");
                if (!map.containsKey(temp[0])) map.put(temp[0], num++);
                int x = map.get(temp[0]);
                if (!map.containsKey(temp[1])) map.put(temp[1], num++);
                int y = map.get(temp[1]);
                ufds.union(x, y);
                pw.println(ufds.size(y));
            }
        }
        pw.close();
    }
}