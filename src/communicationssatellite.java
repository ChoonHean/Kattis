import java.util.*;
import java.io.*;

public class Main {
    static Reader io = new Reader();

    public static void main(String[] args) {
        int n = io.nextInt();
        class Pair {
            int x;
            int y;
            int z;

            Pair(int[] a) {
                this.x = a[0];
                this.y = a[1];
                this.z = a[2];
            }

            Pair(int a, int b, int c) {
                x = a;
                y = b;
                z = c;
            }

            double dist(Pair p) {
                int a = x - p.x;
                int b = y - p.y;
                return Math.sqrt(a * a + b * b) - z - p.z;
            }
        }
        class Trip implements Comparable<Trip> {
            int u, v;
            double w;

            Trip(double w, int u, int v) {
                this.w = w;
                this.u = u;
                this.v = v;
            }

            @Override
            public int compareTo(Trip t) {
                return Double.compare(w, t.w);
            }
        }
        UFDS set = new UFDS(n);
        Pair[] a = new Pair[n];
        PriorityQueue<Trip> pq = new PriorityQueue<>(n * n);
        for (int i = 0; i < n; i++) {
            Pair curr = new Pair(io.nextIntLine());
            a[i] = curr;
            for (int j = 0; j < i; j++) {
                pq.add(new Trip(curr.dist(a[j]), i, j));
            }
        }
        double max = 0;
        while (n-- > 1) {
            Trip e = pq.poll();
            int first = set.find(e.u), second = set.find(e.v);
            if (first == second) {
                n++;
                continue;
            }
            max+=e.w;
            set.union(first, second);
        }
        io.println(max);
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
