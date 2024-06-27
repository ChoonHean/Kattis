import java.util.*;
import java.io.*;

public class Main {
    static Reader io = new Reader();

    public static void main(String[] args) {
        int t=io.nextInt();
        while (t-->0) {
            String commands=io.nextLine();
            int n=io.nextInt();
            List<Integer> ls=new ArrayList<>();
            String[] s=io.nextLine().split(",");
            if (n>0) {
                s[0]=s[0].replaceAll("\\[","");
                s[s.length-1]=s[s.length-1].replaceAll("]","");
            }
            for (int i=0;i<n;i++) {
                ls.add(Integer.parseInt(s[i]));
            }
            boolean reversed = false;
            boolean ok = true;
            int front=0;
            int end=ls.size()-1;
            for (char c:commands.toCharArray()) {
                if (c=='R') reversed=!reversed;
                else {
                    if (front>end) {
                        ok = false;
                        break;
                    } else {
                        if (reversed) end--;
                        else front++;
                    }
                }
            }
            if (ok) {
                io.print("[");
                if (reversed) {
                    while (end>front) {
                        io.print(ls.get(end--)+",");
                    }
                    if (end>=0) io.println(ls.get(end)+"]");
                    else io.println("]");
                } else {
                    while (front<end) {
                        io.print(ls.get(front++)+",");
                    }
                    if (front<n) io.println(ls.get(front)+"]");
                    else io.println("]");
                }
            } else io.println("error");
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