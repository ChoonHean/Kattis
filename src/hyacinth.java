import java.io.*;
import java.util.*;

class Main {
    static int[] visited;
    static int prev=0;
    static List<Integer>[] edges;
    static int[][] ans;
    static int curr=1;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = Integer.parseInt(br.readLine());
        visited = new int[n];
        edges = new List[n];
        for(int i=0;i<n;i++)edges[i]=new ArrayList<>();
        ans = new int[n][2];
        for (int i=1;i<n;i++){
            String[] temp=br.readLine().split(" ");
            int a=Integer.parseInt(temp[0])-1,b=Integer.parseInt(temp[1])-1;
            edges[a].add(b);
            edges[b].add(a);
        }
        ans[prev][0]=curr++;
        visit(0);
        Arrays.stream(ans).map(x->x[0]+" "+x[1]).forEach(pw::println);
        pw.close();
    }
    static void visit(int n) {
        int p=prev;
        ans[n][0]=ans[prev][visited[prev]++%2];
        ans[n][1]=curr++;
        visited[n]=1;
        List<Integer>ls=edges[n];
        if(ls.size()==1){
            ans[n][0]=ans[prev][0];
            ans[n][1]=ans[prev][1];
            if(visited[ls.get(0)]==0)visit(ls.get(0));
        }else{
            prev=n;
            for(int j:ls){
                if(visited[j]==0){
                    visit(j);
                }
            }
            prev=p;
        }
    }
}
