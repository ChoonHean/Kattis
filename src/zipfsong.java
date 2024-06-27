import java.util.*;
import java.io.*;

public class Main {
    static Reader io = new Reader();

    public static void main(String[] args) {
        int n=io.nextInt(),p=io.nextInt();
        class Pair implements Comparable<Pair>{
            final long score;
            final String name;
            final int pos;
            Pair(long score, String name, int pos) {
                this.score=score;
                this.name=name;
                this.pos=pos;
            }
            public int compareTo(Pair p) {
                int a= Long.compare(p.score,score);
                return a==0?pos-p.pos:a;
            }
        }
        PriorityQueue<Pair> pq=new PriorityQueue<>();
        for (int i=1;i<=n;i++) {
            String[] temp=io.nextLine().split(" ");
            pq.add(new Pair(Long.parseLong(temp[0])*i,temp[1],i));
        }
        while (p-->0) {
            io.println(pq.poll().name);
        }
        io.flush();
    }

    static class Reader extends PrintWriter {
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
}