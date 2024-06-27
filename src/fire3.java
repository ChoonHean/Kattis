import java.util.*;
import java.io.*;

public class Main {
    static Reader io = new Reader();
    static int mod = (int) 1e9 + 7;

    public static void main(String[] args) {
        int r=io.nextInt(),c=io.nextInt();
        int[][]fire=new int[r][c];
        int[][]joe=new int[r][c];
        for (int i=0;i<r;i++){
            Arrays.fill(fire[i],mod);
            Arrays.fill(joe[i],mod);

        }
        List<Integer>firepos=new ArrayList<>();
        int joepos=0;
        for (int i=0;i<r;i++){
            String s=io.nextLine();
            for (int j=0;j<c;j++){
                char chr=s.charAt(j);
                if (chr=='#'){
                    fire[i][j]=-1;
                    joe[i][j]=-1;
                } else if (chr=='J') joepos=i*c+j;
                else if (chr=='F') firepos.add(i*c+j);
            }
        }
        Deque<Integer> q = new ArrayDeque<>(firepos);
        int counter=1;
        while (!q.isEmpty()) {
            int size=q.size();
            for (int s=0;s<size;s++){
                int curr=q.poll();
                int row=curr/c,col=curr%c;
                if (counter<fire[row][col]) {
                    fire[row][col]=counter;
                    if (row != 0) q.add(curr-c);
                    if (row != r-1) q.add(curr+c);
                    if (col != 0) q.add(curr-1);
                    if (col != c-1) q.add(curr+1);
                }
            }
            counter++;
        }
        q = new ArrayDeque<>();
        q.add(joepos);
        counter=1;
        while (!q.isEmpty()) {
            int size=q.size();
            for (int s=0;s<size;s++){
                int curr=q.poll();
                int row=curr/c,col=curr%c;
                if (counter<joe[row][col]) {
                    joe[row][col]=counter;
                    if (row != 0 && row != r - 1 && col != 0 && col != c - 1) {
                        q.add(curr+1);
                        q.add(curr-1);
                        q.add(curr+c);
                        q.add(curr-c);
                    }
                }
            }
            counter++;
        }
        int ans=Integer.MAX_VALUE;
        r--;
        c--;
        for (int i=0;i<=c;i++){
            if (joe[0][i]<fire[0][i]) ans=Integer.min(ans,joe[0][i]);
            if (joe[r][i]<fire[r][i]) ans=Integer.min(ans,joe[r][i]);
        }
        for (int i=1;i<r;i++){
            if (joe[i][0]<fire[i][0]) ans=Integer.min(ans,joe[i][0]);
            if (joe[i][c]<fire[i][c]) ans=Integer.min(ans,joe[i][c]);
        }
        //Arrays.stream(fire).forEach(x->io.println(Arrays.toString(x)));
        //Arrays.stream(joe).forEach(x->io.println(Arrays.toString(x)));
        if (ans==Integer.MAX_VALUE) io.println("IMPOSSIBLE");
        else io.println(ans);
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