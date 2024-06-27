import java.util.*;
import java.io.*;

public class Main {
    static Reader io = new Reader();

    public static void main(String[] args) {
        int h = io.nextInt();
        int w = io.nextInt();
        int xlim = h << 1;
        int ylim = w << 1;
        String[][] grid = new String[h][];
        for (int i = 0; i < h; i++) grid[i] = io.nextLine().split("");
        int[][] dp = new int[xlim+1][ylim+1];
        for (int i = 0; i < xlim; i++) {
            for (int j = 0; j < ylim; j++) {
                if (i % 2 == 0) {
                    if (j % 2 == 1) {
                        dp[i + 1][j + 1] = Integer.max(dp[i + 1][j + 1], dp[i][j] + (grid[i / 2][j / 2].equals("O") ? 1 : 0));
                        if (j < ylim - 1) {
                            dp[i][j + 2] = Integer.max(dp[i][j + 2], dp[i][j]);
                        }
                    }
                } else {
                    if (j % 2 == 0) {
                        dp[i + 1][j + 1] = Integer.max(dp[i + 1][j + 1], dp[i][j] + (grid[i / 2][j / 2].equals("O") ? 1 : 0));
                        if (i < xlim - 1) {
                            dp[i + 2][j] = Integer.max(dp[i + 2][j], dp[i][j]);
                        }
                    }
                }
            }
        }
        for (int i=0;i<xlim;i++){
            dp[i+1][ylim]=Integer.max(dp[i][ylim],dp[i+1][ylim]);
        }
        for (int i=0;i<ylim;i++) {
            dp[xlim][i+1]=Integer.max(dp[xlim][i],dp[xlim][i+1]);
        }
        double disc = 10 - 0.25 * Math.PI * 10;
        io.println((h + w) * 10 - disc * Integer.max(dp[xlim - 1][ylim], dp[xlim][ylim - 1]));
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
