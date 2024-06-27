import java.util.*;
import java.io.*;

public class Main {
    static FastReader io = new FastReader();

    public static void main(String[] args) throws IOException {
        int t = io.nextInt();
        while (t-- > 0) {
            int n = io.nextInt();
            TreeSet<String> tree = new TreeSet<>();
            while (n-- > 0) {
                String s = io.nextLine();
                StringBuilder sb = new StringBuilder();
                String[] sarr = s.split(" ");
                String[] proc = sarr[1].split("-");
                for (int i = proc.length - 1; i >= 0; i--) {
                    if (proc[i].charAt(0) == 'm') sb.append('b');
                    else if (proc[i].charAt(0) == 'l') sb.append('c');
                    else if (proc[i].charAt(0) == 'u') sb.append('a');
                }
                while (sb.length() < 10) sb.append('b');
                tree.add(sb.append(sarr[0].substring(0, sarr[0].length() - 1)).toString());
            }
            tree.forEach(x -> io.println(x.substring(10)));
            io.println("=".repeat(30));
        }
        io.flush();
    }

    static class FastReader extends PrintWriter {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
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
}