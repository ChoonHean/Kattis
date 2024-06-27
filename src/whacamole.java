import java.util.*;
import java.io.*;

public class Main {
    static Reader io = new Reader();
    static int mod = (int) 1e9 + 7;

    public static void main(String[] args) {
        while (true) {
            int n = io.nextInt(), d = io.nextInt(), m = io.nextInt();
            if ((n | d | m) == 0) break;
            n += 2 * d;
            int[][][] dp = new int[10][n][n];
            int[][][] mole = new int[10][n][n];
            while (m-- > 0) {
                int[] temp = io.nextIntLine();
                mole[temp[2] - 1][temp[0] + d][temp[1] + d] = 1;
            }
            int dsq = d * d;
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    int hit = mole[0][x][y];
                    dp[0][x][y] = Integer.max(dp[0][x][y], hit);
                    for (int i = -d; i <= d; i++) {
                        for (int j = -d; j <= d; j++) {
                            if ((i | j) == 0) continue;
                            int len = i * i + j * j;
                            int curr = hit;
                            for (int mul = 1; len * mul * mul <= dsq; mul++) {
                                int newx = x + i * mul, newy = y + j * mul;
                                if (newx < 0 || newx >= n || newy < 0 || newy >= n) break;
                                curr += mole[0][newx][newy];
                                dp[0][newx][newy] = Integer.max(dp[0][newx][newy], curr);
                            }
                        }
                    }
                }
            }
            for (int t = 1; t < 10; t++) {
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < n; y++) {
                        int hit = mole[t][x][y] + dp[t - 1][x][y];
                        dp[t][x][y] = Integer.max(dp[t][x][y], hit);
                        for (int i = -d; i <= d; i++) {
                            for (int j = -d; j <= d; j++) {
                                if ((i | j) == 0) continue;
                                int len = i * i + j * j;
                                int curr = hit;
                                for (int mul = 1; len * mul * mul <= dsq; mul++) {
                                    int newx = x + i * mul, newy = y + j * mul;
                                    if (newx < 0 || newx >= n || newy < 0 || newy >= n) break;
                                    curr += mole[t][newx][newy];
                                    dp[t][newx][newy] = Integer.max(dp[t][newx][newy], curr);
                                }
                            }
                        }
                    }
                }
            }
            //Arrays.stream(dp).flatMap(Arrays::stream).forEach(x -> io.println(Arrays.toString(x)));
            io.println(Arrays.stream(dp[9]).flatMapToInt(Arrays::stream).max().getAsInt());
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