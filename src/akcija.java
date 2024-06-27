import java.util.*;
import java.io.*;

public class Main {
    static FastReader io = new FastReader();

    public static void main(String[] args) throws IOException {
        int t=io.nextInt();
        int res=0;
        List<Integer> ls=new ArrayList<>(t);
        while (t-->0) {
            ls.add(io.nextInt());
        }
        Collections.sort(ls,Collections.reverseOrder());
        for (int i=0;i<ls.size();i++) {
            if (i%3==2) continue;
            res+=ls.get(i);
        }
        io.println(res);
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