import java.io.*;
import java.util.stream.*;
class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int width = Integer.parseInt(br.readLine());
        br.readLine();
        Stream<String> s = br.lines();
        int total = s.map(x -> Integer.parseInt(x.substring(0,1)) * Integer.parseInt(x.substring(2,3))).reduce(0, (x, y) -> x + y);
        pw.println(total / width);
        pw.close();
    }
}