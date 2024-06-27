import java.util.*;
import java.io.*;

public class Main {
    static Reader io = new Reader();
    static int[][] mat;
    static int[][][] memo;
    static int n;
    static boolean[] visited;
    public static void main(String[] args) {
        n=io.nextInt();
        int f=io.nextInt();
        mat=new int[n][];
        memo=new int[n][n][f+1];
        for (int i=0;i<n;i++)mat[i]=io.nextIntLine();
        int max=0;
        for (int i=0;i<n;i++) {
            max=Integer.max(max,f(0,i,f));
            max=Integer.max(max,f(i,0,f));
            max=Integer.max(max,f(n-1,i,f));
            max=Integer.max(max,f(i,n-1,f));
        }
        io.println(max);
        io.flush();
    }
    static int f(int x, int y, int f) {
        if (f==0)return mat[x][y];
        int[] curr=memo[x][y];
        if (curr[f]!=0)return curr[f];
        int val=mat[x][y];
        int a=0;
        if(x>0) if(mat[x-1][y]>val) a=f(x-1,y,f-1);
        if(x<n-1) if(mat[x+1][y]>val) a=Integer.max(a,f(x+1,y,f-1));
        if(y>0) if(mat[x][y-1]>val) a=Integer.max(a,f(x,y-1,f-1));
        if(y<n-1) if(mat[x][y+1]>val) a=Integer.max(a,f(x,y+1,f-1));
        val+=a;
        curr[f]=val;
        return val;
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