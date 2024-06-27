import java.util.*;
import java.io.*;

public class Main {
    static Reader io = new Reader();

    public static void main(String[] args) {
        int n=io.nextInt(),m=io.nextInt();
        int[][]cost=new int[m][n+1];
        for (int i=0;i<m;i++){
            int j=io.nextInt();
            cost[i][n]= io.nextInt();
            while (j-->0){
                cost[i][io.nextInt()-1]=io.nextInt();
            }
        }
        for (int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (cost[i][j]==0)cost[i][j]=Integer.MAX_VALUE;
            }
        }
        int res=Integer.MAX_VALUE;
        int[][]dp=new int[1<<m][n+1];
        for (int i=0;i<n;i++) dp[0][i]=Integer.MAX_VALUE;
        for (int i=0;i<m;i++){
            int[]store=cost[i];
            for (int j=0;j<1<<i;j++){
                int[]curr=dp[j];
                int[]next=dp[j|1<<i];
                for (int k=0;k<n;k++){
                    next[k]=Integer.min(curr[k],store[k]);
                }
                next[n]=curr[n]+store[n];
                int total=0;
                boolean ok=true;
                for (int k:next){
                    if (k==Integer.MAX_VALUE){
                        ok=false;
                        break;
                    }else total+=k;
                }
                if(ok)res=Integer.min(res,total);
            }
        }
        io.println(res);
        io.flush();
    }

    static void p(int[] a) {io.println(Arrays.toString(a));}
    static void p(double[] a) {io.println(Arrays.toString(a));}
    static void p(Object o) {
        if (o instanceof Object[] oa) io.println(Arrays.deepToString(oa));
        else io.println(o);
    }
}

class Reader extends PrintWriter {
    BufferedReader br;
    StringTokenizer st;

    public Reader() {
        super(new BufferedOutputStream(System.out));
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    String next() {
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    long nextLong() {
        return Long.parseLong(next());
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }

    String nextLine() {
        String str = null;
        try {
            while (str == null) {
                if (st != null) {
                    if (st.hasMoreTokens()) {
                        str = "";
                        while (st.hasMoreTokens()) {
                            str += st.nextToken("\n");
                        }
                    } else {
                        str = br.readLine();
                    }
                } else {
                    str = br.readLine();
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }

    int[] nextIntLine() {
        String[] temp = nextLine().split(" ");
        int[] a = new int[temp.length];
        for (int i = 0; i < temp.length; i++) {
            a[i] = Integer.parseInt(temp[i]);
        }
        return a;
    }

    long[] nextLongLine() {
        String[] temp = nextLine().split(" ");
        long[] a = new long[temp.length];
        for (int i = 0; i < temp.length; i++) {
            a[i] = Long.parseLong(temp[i]);
        }
        return a;
    }

    double[] nextDoubleLine() {
        String[] temp = nextLine().split(" ");
        double[] a = new double[temp.length];
        for (int i = 0; i < temp.length; i++) {
            a[i] = Double.parseDouble(temp[i]);
        }
        return a;
    }
}