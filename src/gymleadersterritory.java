import java.util.*;
import java.io.*;

public class Main {
    static Reader io = new Reader();

    public static void main(String[] args) {
        int n = io.nextInt(),k= io.nextInt(),m= io.nextInt();
        List<Integer>[] adj=new ArrayList[n+1];
        for (int i=1;i<=n;i++)adj[i]=new ArrayList<>();
        while(m-->0){
            int[] temp=io.nextIntLine();
            int a=temp[0],b=temp[1];
            adj[a].add(b);
            adj[b].add(a);
        }
        boolean found = false;
        for (int neighbour:adj[k]) {
            boolean[] visited = new boolean[n + 1];
            Deque<Integer> q = new ArrayDeque<>();
            q.add(neighbour);
            adj[neighbour].remove(Integer.valueOf(k));
            while (!q.isEmpty()) {
                int curr = q.pop();
                for (int i : adj[curr]) {
                    if (i == k) {
                        found = true;
                        break;
                    }
                    if (!visited[i]) {
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }
            if (found)break;
            adj[neighbour].add(k);
        }
        if (found)io.println("NO");
        else io.println("YES");
        io.flush();
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
