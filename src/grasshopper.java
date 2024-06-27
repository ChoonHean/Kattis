import java.awt.desktop.QuitEvent;
import java.util.*;
import java.io.*;

public class Main {
    static FastReader io = new FastReader();
    static int[][] grid;
    static Queue<Point> queue;
    static int row, col;
    static boolean found;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedOutputStream(System.out));
        String input;

        while ((input = br.readLine()) != null) {
            String[] temp = input.split(" ");
            row = Integer.parseInt(temp[0]);
            col = Integer.parseInt(temp[1]);
            grid = new int[row][col];
            grid[Integer.parseInt(temp[4]) - 1][Integer.parseInt(temp[5]) - 1] = 2;
            queue = new ArrayDeque<>();
            queue.add(new Point(Integer.parseInt(temp[2]) - 1, Integer.parseInt(temp[3]) - 1));
            int jumps = 0;
            found = false;
            Point point = queue.peek();
            if (grid[point.x][point.y] == 2) pw.println(jumps);
            else {
                grid[point.x][point.y] = 1;
                while (!queue.isEmpty()) {
                    int size = queue.size();
                    while (size-- > 0) {
                        point = queue.poll();
                        int x = point.x, y = point.y;
                        f(x + 1, y + 2);
                        f(x + 1, y - 2);
                        f(x - 1, y + 2);
                        f(x - 1, y - 2);
                        f(x + 2, y + 1);
                        f(x + 2, y - 1);
                        f(x - 2, y + 1);
                        f(x - 2, y - 1);
                        if (found) break;
                    }
                    jumps++;
                    if (found) {
                        pw.println(jumps);
                        break;
                    }
                }
                if (!found) pw.println("impossible");
            }
        }
        pw.close();
    }
    static void f(int x, int y) {
        if (x >=0 && x < row) {
            if (y >=0 && y < col) {
                int p = grid[x][y];
                if (p == 2) found = true;
                else if (p == 0) {
                    queue.add(new Point(x, y));
                    grid[x][y] = 1;
                }
            }
        }
    }
    static class Point {
        final int x;
        final int y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
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