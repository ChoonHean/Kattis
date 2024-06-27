import java.util.*;
import java.io.*;

public class Main {
    static Reader io = new Reader();
    /*static int[][]mat;
    static int r,c,maxq,n,size,min,max;
    static int[] ans;

    public static void main(String[] args) {
        r = io.nextInt();
        c = io.nextInt();
        mat = new int[r][];
        for (int i = 0; i < r; i++) mat[i] = io.nextIntLine();
        int q = io.nextInt();
        List<Integer> ls = new ArrayList<>(q);
        maxq = 0;
        for (int i = 0; i < q; i++) {
            int curr = io.nextInt();
            maxq = Integer.max(maxq, curr);
            ls.add(curr);
        }
        n = r * c;
        boolean[] visited = new boolean[n];
        ans = new int[n + 1];
        Arrays.fill(ans, Integer.MAX_VALUE);
        ans[0] = 0;
        for (int i : ls) io.println(ans[i]);
        io.flush();
    }*/
    public static void main(String[] args) {
        int n=io.nextInt();
        int[][] dp=new int[2][n+1];
        int[] a= io.nextIntLine();
        dp[1][0]=0;
        for (int i=0;i<n;i++) {
            dp[1][i+1]=Integer.min(dp[0][i],dp[1][i])+a[i];
            dp[0][i+1]=dp[1][i];
        }
        io.println(Integer.min(dp[0][n],dp[1][n]));
        io.flush();
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