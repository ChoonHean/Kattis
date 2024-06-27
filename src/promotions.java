import java.util.*;
import java.io.*;

public class Main {
    static List<Integer>[] adj;
    static List<Integer>[] transpose;
    static boolean[] visited;
    static int pos;
    static FastReader io = new FastReader();

    public static void main(String[] args) throws IOException {
        int[] temp=io.nextIntLine();
        int a=temp[0],b=temp[1],n=temp[2],p=temp[3];
        adj=new ArrayList[n];
        transpose=new ArrayList[n];
        for (int i=0;i<n;i++) {
            adj[i]=new ArrayList<>();
            transpose[i]=new ArrayList<>();
        }
        while (p-->0) {
            int[] temp1= io.nextIntLine();
            int q=temp1[0],w=temp1[1];
            adj[q].add(w);
            transpose[w].add(q);
        }
        int ans1=0,ans2=0,ans3=0;
        for (int i=0;i<n;i++) {
            pos=-1;
            visited = new boolean[n];
            dfs(i);
            if (n-pos<=a) {
                ans1++;
                ans2++;
            } else if (n-pos<=b) {
                ans2++;
            } else {
                pos=-1;
                visited = new boolean[n];
                dfsreverse(i);
                if (pos>=b) ans3++;
            }
        }
        io.println(ans1);
        io.println(ans2);
        io.println(ans3);
        io.flush();
    }
    static void dfs(int n) {
        pos++;
        visited[n]=true;
        for (int i:adj[n]) if (!visited[i]) dfs(i);
    }
    static void dfsreverse(int n) {
        pos++;
        visited[n] = true;
        for (int i:transpose[n]) if (!visited[i]) dfsreverse(i);
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
                    if (st!=null) {
                        str = "";
                        while (st.hasMoreTokens()) {
                            str += st.nextToken("\n");
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