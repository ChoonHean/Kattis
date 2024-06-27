import java.io.*;
import java.util.*;

class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        String[] temp = br.readLine().split(" ");
        int n = Integer.parseInt(temp[0]), m=Integer.parseInt(temp[1]);
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
                x=findSet(x);
                y=findSet(y);
                if(x==1)p[y]=x;
                else p[x]=y;
            }
        }
        UFDS ufds = new UFDS(n+1);
        for(int i=0;i<m;i++){
            temp=br.readLine().split(" ");
            ufds.union(Integer.parseInt(temp[0]),Integer.parseInt(temp[1]));
        }
        List<Integer> res = new ArrayList<>();
        for (int i=1;i<=n;i++) if(ufds.findSet(i)!=1) res.add(i);
        if (res.isEmpty())pw.println("Connected");
        else res.forEach(pw::println);
        pw.close();
    }
}
