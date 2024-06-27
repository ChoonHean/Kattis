import java.io.*;
import java.util.*;
import java.util.stream.Stream;

class Solution {
    static PrintStream p = System.out;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        String[] temp = br.readLine().split(" ");
        int k = Integer.parseInt(temp[0]); //airports
        int n = Integer.parseInt(temp[1]); //days
        int m = Integer.parseInt(temp[2]); //flights
        int[][] flights = new int[m][];
        for (int i = 0; i < m; i++) flights[i] = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        Arrays.sort(flights, Comparator.comparing(x -> x[2]));
        int[][] people = new int[k * n][];
        for (int i = 0; i < k * n; i++) people[i] = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        Arrays.sort(people, Comparator.comparing(x -> x[1]));
        int day = 0;
        int[] num = new int[k];
        int[] arrived = new int[k];
        for (int[] flight : flights) {
            if (flight[2] > day) {
                update(num, arrived, people, day);
                day++;
            }
            num[flight[0]-1] -= flight[3];
            if (num[flight[0]-1] < 0) {
                pw.println("suboptimal");
                pw.close();
                return;
            }
            arrived[flight[1]-1] += flight[3];
        }
        pw.println("optimal");
        pw.close();
    }
    static void update(int[] num, int[] arrived, int[][] people, int day) {
        int n = num.length;
        for (int i = 0; i < n; i++) {
            num[i] += arrived[i];
            arrived[i] = 0;
        }
        for (int i = day * n; i < day * n + n; i++) {
            num[people[i][0]-1] += people[i][2];
        }
    }
}