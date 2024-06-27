import java.io.*;
import java.util.*;

class Main {

    public static void main(String[] args) throws IOException {
        int[][][] maze = new int[201][201][4]; //-1=wall, 1=entered
        int x=100,y=100;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        String up="up",right="right",left="left",down="down";
        int loc = 0;
        pw.println(up);
        pw.flush();
        boolean unsolvable = false;
        while (true) {
            int l = br.readLine().length();
            if (l>4) return;
            if (l==2){
                maze[x][y][loc]=1;
                loc+=2;
                switch (loc) {
                    case 2 -> x++;
                    case 3 -> y++;
                    case 4 -> x--;
                    case 5 -> y--;
                }
                } else maze[x][y][loc]=-1;
            loc++;
            loc%=4;
            for(int i=0;i<4;i++){
                if(maze[x][y][loc]==0) {
                    break;
                } else {
                    loc++;
                    loc%=4;
                }
                if(i==3)unsolvable=true;
            }
            if (unsolvable) {
                pw.println("no way out");
                pw.flush();
                continue;
            }
            pw.println(loc==0?up:loc==1?right:loc==2?down:left);
            pw.flush();
        }
    }
}
