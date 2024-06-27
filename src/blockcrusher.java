import java.util.*;
import java.io.*;

public class Main {
    static Reader io = new Reader();
    static int mod = (int) 1e9 + 7;

    public static void main(String[] args) {
        class Path{
            List<Integer>path=new ArrayList<>();
            int w=0;
            int last=0;
        }
        while (true){
            int h=io.nextInt(),w= io.nextInt();
            if ((h|w)==0)break;
            int[][]mat=new int[h][w];
            for (int i=0;i<h;i++)mat[i]=Arrays.stream(io.nextLine().split("")).mapToInt(Integer::parseInt).toArray();
            PriorityQueue<Path>pq=new PriorityQueue<>(Comparator.comparingInt(x->x.w));
            for (int i=0;i<w;i++){
                Path p=new Path();
                p.path.add(i);
                p.w=mat[0][i];
                p.last=i;
                pq.add(p);
            }
            boolean[][]visited=new boolean[h][w];
            Path ans,p;
            while (true){
                Path curr=pq.poll();
                int row=curr.last/w,col=curr.last%w;
                if (row==h-1){
                    ans=curr;
                    break;
                }
                if (visited[row][col]) continue;
                visited[row][col]=true;
                if (col!=0) {
                    if (!visited[row+1][col-1]) {
                        p = new Path();
                        p.last = curr.last + w - 1;
                        p.path.addAll(curr.path);
                        p.path.add(p.last);
                        p.w = curr.w + mat[row + 1][col - 1];
                        pq.add(p);
                    }
                    if (!visited[row][col-1]) {
                        p = new Path();
                        p.last = curr.last - 1;
                        p.path.addAll(curr.path);
                        p.path.add(p.last);
                        p.w = curr.w + mat[row][col - 1];
                        pq.add(p);
                    }
                    if (row!=0) {
                        if (!visited[row-1][col-1]) {
                            p = new Path();
                            p.last = curr.last - w - 1;
                            p.path.addAll(curr.path);
                            p.path.add(p.last);
                            p.w = curr.w + mat[row - 1][col - 1];
                            pq.add(p);
                        }
                    }
                }
                if (col!=w-1){
                    if (!visited[row+1][col+1]) {
                        p = new Path();
                        p.last = curr.last + w + 1;
                        p.path.addAll(curr.path);
                        p.path.add(p.last);
                        p.w = curr.w + mat[row + 1][col + 1];
                        pq.add(p);
                    }
                    if (!visited[row][col+1]) {
                        p = new Path();
                        p.last = curr.last + 1;
                        p.path.addAll(curr.path);
                        p.path.add(p.last);
                        p.w = curr.w + mat[row][col + 1];
                        pq.add(p);
                    }
                    if (row!=0) {
                        if (!visited[row-1][col+1]) {
                            p = new Path();
                            p.last = curr.last - w + 1;
                            p.path.addAll(curr.path);
                            p.path.add(p.last);
                            p.w = curr.w + mat[row - 1][col + 1];
                            pq.add(p);
                        }
                    }
                }
                if (!visited[row+1][col]) {
                    curr.last += w;
                    curr.path.add(curr.last);
                    curr.w += mat[row + 1][col];
                    pq.add(curr);
                }
            }
            for (int i:ans.path){
                mat[i/w][i%w]=0;
            }
            for (int[]a:mat){
                for (int i:a){
                    if (i==0)io.print(" ");
                    else io.print(i);
                }
                io.println();
            }
            io.println();
        }
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