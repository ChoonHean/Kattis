import java.util.*;
import java.io.*;

public class Main {
    static Reader io = new Reader();

    public static void main(String[] args) throws IOException {
        String input;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while ((input = br.readLine()) != null) {
            int n = Integer.parseInt(input);
            Queue<Integer> queue = new ArrayDeque<>();
            Deque<Integer> stack = new ArrayDeque<>();
            PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
            boolean[] possible = new boolean[3];
            Arrays.fill(possible, true);
            while (n-- > 0) {
                String[] temp = br.readLine().split(" ");
                int a=Integer.parseInt(temp[0]),b=Integer.parseInt(temp[1]);
                if (a == 1) {
                    queue.add(b);
                    stack.push(b);
                    pq.add(b);
                } else {
                    if (queue.peek() == null) possible[0] = false;
                    else if (queue.poll() != b) possible[0] = false;
                    if (stack.peekFirst() == null) possible[1] = false;
                    else if (stack.pop() != b) possible[1] = false;
                    if (pq.peek() == null) possible[2] = false;
                    else if (pq.poll() != b) possible[2] = false;
                }
            }
            if (possible[0]) {
                if (possible[1] || possible[2]) io.println("not sure");
                else io.println("queue");
            } else if (possible[1]) {
                if (possible[2]) io.println("not sure");
                else io.println("stack");
            } else if (possible[2]) io.println("priority queue");
            else io.println("impossible");
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