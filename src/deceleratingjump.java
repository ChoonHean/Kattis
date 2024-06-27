import java.util.*;
import java.io.*;

public class Main {
    static Reader io = new Reader();

    public static void main(String[] args) {
        int n=io.nextInt();
        long[] val=io.nextLongLine();
        long[][] dp=new long[n][n];
        for (int i=1;i<n;i++){
            dp[i][i]=val[0]+val[i];
            for (int j=i-1;j>i/2;j--){
                dp[j][i]=dp[j+1][i];
            }
            for (int j=i/2;j>0;j--){
                dp[j][i]=Long.max(dp[j+1][i],dp[j][i-j]+val[i]);
            }
        }
         //Arrays.stream(dp).forEach(x->System.out.println(Arrays.toString(x)));
        io.println(dp[1][n-1]);
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