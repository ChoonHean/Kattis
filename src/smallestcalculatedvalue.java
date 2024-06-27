import java.util.*;
import java.io.*;

public class Main {
    static FastReader io = new FastReader();

    public static void main(String[] args) throws IOException {
        int a=io.nextInt(),b=io.nextInt(),c=io.nextInt();
        int res = Integer.MAX_VALUE;
        List<Integer> ls = new ArrayList<>();
        ls.add(a+b);
        ls.add(a*b);
        ls.add(a-b);
        if (a%b==0)ls.add(a/b);
        for (int i : ls) {
            int d=i+c;
            if (d>=0)res=Integer.min(res,d);
            d=i-c;
            if (d>=0)res=Integer.min(res,d);
            if (i%c==0) {
                d=i/c;
                if (d>=0) res=Integer.min(res,d);
            }
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
            String str = "";
            try {
                if (st.hasMoreTokens()) {
                    str = st.nextToken("\n");
                } else {
                    str = br.readLine();
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