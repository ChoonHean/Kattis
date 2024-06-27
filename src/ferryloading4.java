import java.util.*;
import java.io.*;

public class Main {
    static Reader io = new Reader();

    public static void main(String[] args) {
        int t=io.nextInt();
        while (t-->0){
            int res=0;
            int l= io.nextInt()*100;
            Deque<Integer> leftcars=new ArrayDeque<>(),rightcars=new ArrayDeque<>();
            int no=io.nextInt();
            for (int i=0;i<no;i++) {
                String[] temp = io.nextLine().split(" ");
                if (temp[1].equals("left")) leftcars.add(Integer.parseInt(temp[0]));
                else rightcars.add(Integer.parseInt(temp[0]));
            }
            boolean left=true;
            while (!leftcars.isEmpty()||!rightcars.isEmpty()){
                int space=l;
                if (left) {
                    while (!leftcars.isEmpty()) {
                        if (leftcars.peek() <= space) space -= leftcars.poll();
                        else break;
                    }
                    if (space==l&&rightcars.isEmpty()) break;
                } else {
                    while (!rightcars.isEmpty()) {
                        if (rightcars.peek() <= space) space -= rightcars.poll();
                        else break;
                    }
                    if (space==l&&leftcars.isEmpty()) break;
                }
                left=!left;
                res++;
            }
            io.println(res);
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