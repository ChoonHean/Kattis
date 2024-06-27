import java.util.*;
import java.io.*;

public class Main {
    static Reader io = new Reader();
    static double[][] edges;
    static Deque<Integer> q=new ArrayDeque<>();
    static boolean[] visited;
    static int l,p;

    public static void main(String[] args) {
        l=io.nextInt();
        p=io.nextInt();
        double[] dp=new double[l+p+1];
        double[] prob=new double[l+p+1];
        visited=new boolean[l+p+1];
        for (int i=1;i<=l;i++){
            prob[i]=1;
            dp[i]=io.nextInt();
        }
        edges=new double[p+1][];
        boolean[] drop=new boolean[l+p+1];
        Arrays.fill(drop, true);
        for (int i=1;i<=p;i++){
            double[] curr=io.nextDoubleLine();
            edges[i]=curr;
            drop[(int)curr[2]]=false;
            drop[(int)curr[3]]=false;
        }
        for (int i=l+1;i<=l+p;i++) if (!visited[i]) dfs(i);
        while (!q.isEmpty()) {
            int next=q.poll();
            double[]curr=edges[next-l];
            dp[next]=curr[0]*dp[(int)curr[2]]+curr[1]*dp[(int)curr[3]];
            prob[next]=curr[0]*prob[(int)curr[2]]+curr[1]*prob[(int)curr[3]];
        }
        double res=0;
        for (int i=1;i<=l+p;i++) if(drop[i]) res=Double.max(res,dp[i]/prob[i]);
        io.println(res);
        io.flush();
    }
    static void dfs(int n) {
        if (n>l) {
            visited[n]=true;
            double[]curr=edges[n-l];
            if (!visited[(int)curr[2]]) dfs((int)curr[2]);
            if (!visited[(int)curr[3]]) dfs((int)curr[3]);
            q.add(n);
        }
    }
    static void p(int[] a) {io.println(Arrays.toString(a));}
    static void p(double[] a) {io.println(Arrays.toString(a));}
    static void p(Object o) {
        if (o instanceof Object[] oa) io.println(Arrays.deepToString(oa));
        io.println(o);
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