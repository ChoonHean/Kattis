import java.util.*;
public class numberfun{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = n; i > 0; i--){
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            if (a + b == c){
                System.out.println("Possible");
            } else if (a * b == c) {
                System.out.println("Possible");
            } else if (Math.abs(a - b) == c) {
                System.out.println("Possible");
            } else if ((double)a / b == c) {
                System.out.println("Possible");
            } else if ((double)b / a == c) {
                System.out.println("Possible");
            } else {
                System.out.println("Impossible");
            }
        }
    }
}