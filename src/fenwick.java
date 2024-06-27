import java.util.*;
import java.io.*;

public class Main {
    static Reader io = new Reader();

    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }
        io.flush();
    }

    static void solve() {
        int n=io.nextInt(),q=io.nextInt();
        FenwickTree ft=new FenwickTree(n);
        while (q-- > 0) {
            String[] temp = io.nextLine().split(" ");
            if (temp[0].equals("+")) {
                ft.update(Integer.parseInt(temp[1]), Integer.parseInt(temp[2]));
            } else {
                io.println(ft.query(Integer.parseInt(temp[1])-1));
            }
        }
        io.println();
    }
    static class FenwickTree {
        long[] ft;
        int n;

        FenwickTree(int n) {
            ft = new long[n+1];
            this.n = n;
        }

        int lsb(int i) {
            return i & -i;
        }

        void update(int pos, int val) {
            if (pos == 0) {
                ft[0] += val;
            } else {
                while (pos < n) {
                    ft[pos] += val;
                    pos = pos + lsb(pos);
                }
            }
        }

        long query(int end) {
            if (end < 0) return 0;
            long ans = 0;
            while (end > 0) {
                ans += ft[end];
                end -= lsb(end);
            }
            return ans + ft[0];
        }

        long query(int start, int end) {
            return query(end) - query(start);
        }
    }

    static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    static double d(double[] a, double[] b) {
        double x = a[0] - b[0];
        double y = a[1] - b[1];
        return Math.sqrt(x * x + y * y);
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

class Pair implements Comparable<Pair> {
    int x, y;

    Pair(int[] a) {
        this.x = a[0];
        this.y = a[1];
    }

    Pair(int a, int b) {
        x = a;
        y = b;
    }

    double dist(Pair p) {
        double a = x - p.x;
        double b = y - p.y;
        return Math.sqrt(a * a + b * b);
    }

    @Override
    public int compareTo(Pair other) {
        return Integer.compare(x, other.x);
    }

    public boolean equals(Pair other) {
        return x == other.x && y == other.y;
    }

    @Override
    public String toString() {
        return String.format("(%d,%d)", x, y);
    }
}

class Trip implements Comparable<Trip> {
    int u, v;
    int w;

    Trip(int w, int u, int v) {
        this.w = w;
        this.u = u;
        this.v = v;
    }

    @Override
    public int compareTo(Trip t) {
        return Double.compare(w, t.w);
    }

    @Override
    public String toString() {
        return String.format("%d-%d:%f", u, v, w);
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