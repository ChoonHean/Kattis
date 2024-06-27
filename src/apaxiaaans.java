import java.util.Scanner;
import java.util.stream.*;
public class apaxiaaans {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name = sc.nextLine();
        System.out.println(IntStream.range(1, name.length())
        .filter(x -> name.charAt(x)!=name.charAt(x-1))
        .mapToObj(x -> Character.toString(name.charAt(x)))
        .reduce(Character.toString(name.charAt(0)), (x,y)-> x + y));
    }
}