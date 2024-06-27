import java.util.*;
import java.io.*;

public class Main {
    static Reader io = new Reader();

    public static void main(String[] args) {
        while (true) {
            int n = io.nextInt(), b = io.nextInt();
            if (n<0) break;
            List<Integer> ls=new ArrayList<>(n);
            int max=0;
            for (int i=0;i<n;i++) {
                int j=io.nextInt();
                max=Integer.max(max,j);
                ls.add(j);
            }
            int low=1,high=max;
            while (low<high){
                double mid=(high+low)/2;
                int total=0;
                for (int i:ls) total+=(int)Math.ceil(i/mid);
                if (total>b) low=(int)mid+1;
                else high=(int)mid;
            }
            io.println(high);
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