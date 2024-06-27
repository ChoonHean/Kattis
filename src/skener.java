import java.util.*;
import java.util.stream.*;
class skener {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int rowno = sc.nextInt();
        sc.nextInt();
        int col = sc.nextInt();
        int row = sc.nextInt();
        sc.nextLine();
        IntStream.range(0, rowno).mapToObj(x -> sc.nextLine())
        .map(x -> IntStream.range(0, x.length()).mapToObj(y -> String.valueOf(x.charAt(y))).reduce("", (a,b) -> a + b.repeat(row)))
        .flatMap(x -> IntStream.range(0, col).mapToObj(y -> x))
        .forEach(System.out::println);
        sc.close();
    }
}