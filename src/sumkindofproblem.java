import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int num = Integer.parseInt(br.readLine());
        for (int i = 1; i <= num; i++) {
            String[] temp = br.readLine().split(" ");
            int x = Integer.parseInt(temp[1]);
            int y = x * (1 + x) / 2;
            pw.println(String.format("%d %d %d %d", Integer.parseInt(temp[0]), y, y * 2 - x, y * 2));
        }
        pw.close();
    }
}