import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            String[] temp = br.readLine().split(" ");
            HashSet<String> sounds = new HashSet<>();
            while (true) {
                String[] animals = br.readLine().split(" ");
                if (animals.length == 5) {
                    break;
                }
                sounds.add(animals[2]);
            }
            StringBuilder output = new StringBuilder();
            for (String s : temp) {
                if (!sounds.contains(s)) {
                    output.append(" " + s);
                }
            }
            pw.println(output.toString().trim());
        }
        pw.close();
    }
}