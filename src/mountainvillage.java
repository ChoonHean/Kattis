import java.util.*;
import java.io.*;
public class Pair {
    int x, y;

    Pair(int[] a) {
        this.x = a[0];
        this.y = a[1];
    }

    Pair(int a, int b) {
        x = a;
        y = b;
    }

    double dist(Pair p) {
        double a = x - p.x;
        double b = y - p.y;
        return Math.sqrt(a * a + b * b);
    }

    @Override
    public String toString() {
        return String.format("(%d,%d)", x, y);
    }
}

public class Main {
    static Reader io = new Reader();
    static int[][] mat;
    static int r, c, maxq, n, size, min, max, height;
    static int[] ans;
    static PriorityQueue<Pair> pq=new PriorityQueue<>(Comparator.comparingInt(x->x.x));
    static boolean[] used;

    public static void main(String[] args) {
        r = io.nextInt();
        c = io.nextInt();
        mat = new int[r][];
        for (int i = 0; i < r; i++) mat[i] = io.nextIntLine();
        int q = io.nextInt();
        List<Integer> ls = new ArrayList<>(q);
        List<Integer>[] heights=new ArrayList[100];
        for (int i=0;i<100;i++)heights[i]=new ArrayList<>();
        for (int i=0;i<r;i++) for (int j=0;j<c;j++) heights[mat[i][j]].add(i*c+j);
        maxq = 0;
        for (int i = 0; i < q; i++) {
            int curr = io.nextInt();
            maxq = Integer.max(maxq, curr);
            ls.add(curr);
        }
        n = r * c;
        boolean[] visited = new boolean[n];
        ans = new int[n + 1];
        Arrays.fill(ans, 100);
        ans[0]=0;
        if (n>0) ans[1]=0;
        for (int i=0;i<100;i++) {
            List<Integer> currheight=heights[i];
            for (int h:currheight) {
                if (visited[h]) continue;
                used = new boolean[n];
                maxq=0;
                int size=1;
                height=i;
                pq.clear();
                visited[h] = true;
                used[h] = true;
                queue(h);
                if (!pq.isEmpty()) {
                    while (pq.peek().x==0) {
                        Pair p=pq.poll();
                        visited[p.y]=true;
                        queue(p.y);
                        size++;
                        if (pq.isEmpty()) break;
                    }
                }
                for (int k=2;k<=size;k++) ans[k]=0;
                while (!pq.isEmpty()) {
                    Pair p=pq.poll();
                    maxq=Integer.max(maxq,p.x);
                    queue(p.y);
                    size++;
                    ans[size]=Integer.min(ans[size],maxq);
                    //io.println(Arrays.toString(ans));
                }
            }
        }
        for (int i:ls) io.println(ans[i]);
        io.flush();
    }
    static void queue(int n) {
        int x=n/c,y=n%c;
        if (x>0) if (!used[n-c]) {
            used[n-c]=true;
            int diff=mat[x-1][y]-height;
            if (diff>=0) pq.add(new Pair(diff,n-c));
        }
        if (x<r-1) if(!used[n+c]) {
            used[n+c]=true;
            int diff=mat[x+1][y]-height;
            if (diff>=0) pq.add(new Pair(diff,n+c));
        }
        if (y>0) if(!used[n-1]) {
            used[n-1]=true;
            int diff=mat[x][y-1]-height;
            if (diff>=0) pq.add(new Pair(diff, n-1));
        }
        if (y<c-1) if(!used[n+1]) {
            used[n+1]=true;
            int diff=mat[x][y+1]-height;
            if (diff>=0) pq.add(new Pair(diff, n+1));
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