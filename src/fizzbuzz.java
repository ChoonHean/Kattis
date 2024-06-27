import java.util.*;
import java.util.stream.*;
class fizzbuzz {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        IntStream.rangeClosed(1, sc.nextInt())
        .mapToObj(x -> x % a == 0 && x % b == 0 ? "FizzBuzz" : x % a == 0 ? "Fizz" : x % b == 0 ? "Buzz" : x)
        .forEach(System.out::println);
        sc.close();
    }
}