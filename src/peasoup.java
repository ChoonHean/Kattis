import java.util.*;
import java.util.stream.IntStream;

class peasoup {
    public static void main(String[] args) {
        boolean found = false;
        Scanner sc = new Scanner(System.in);
        for (int i = sc.nextInt(); i > 0; i--) {
            int num = sc.nextInt();
            String name = sc.nextLine();
            name = sc.nextLine();
            if (IntStream.range(0,num).mapToObj(x -> sc.nextLine())//.peek(System.out::println)
                    .distinct().filter(x -> x.equals("pea soup") || x.equals("pancakes")).count() == 2) {
                System.out.println(name);
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("Anywhere is fine I guess");
        }
    }
}
