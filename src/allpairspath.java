import java.util.*;
import java.io.*;

public class Main {
    static Reader io = new Reader();
    static int mod = (int) 1e9 + 7;

    public static void main(String[] args) {
        while (true) {
            int n = io.nextInt(), m = io.nextInt(), q = io.nextInt();
            if ((n | m | q) == 0) break;
            int[][] dp = new int[n][n];
            for (int i = 0; i < n; i++) Arrays.fill(dp[i], mod);
            for (int i = 0; i < n; i++) dp[i][i] = 0;
            while (m-- > 0) {
                int u = io.nextInt(), v = io.nextInt(), w = io.nextInt();
                dp[u][v] = Integer.min(dp[u][v], w);
            }
            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        dp[i][j] = Integer.min(dp[i][j], (dp[i][k]==mod||dp[k][j]==mod)?mod:dp[i][k] + dp[k][j]);
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    //if (dp[i][j] == mod) continue;
                    for (int k = 0; k < n; k++) {
                        if (dp[i][k] != mod && dp[k][j] != mod && dp[k][k] < 0) {
                            dp[i][j] = -mod;
                            break;
                        }
                    }
                }
            }
            while (q-- > 0) {
                int w = dp[io.nextInt()][io.nextInt()];
                if (w == mod) io.println("Impossible");
                else if (w == -mod) io.println("-Infinity");
                else io.println(w);
            }
            io.println();
        }
        io.flush();
    }

    static void p(int[] a) {
        io.println(Arrays.toString(a));
    }

    static void p(double[] a) {
        io.println(Arrays.toString(a));
    }

    static void p(Object o) {
        if (o instanceof Object[] oa) {
            io.println(Arrays.deepToString(oa));
        } else {
            io.println(o);
        }
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