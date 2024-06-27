import java.util.*;

public class lastfactorialdigit{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n ; i++) {
            int j = sc.nextInt();
            int res = 1;
            for (int k = j; k > 0; k--) {
                res *= k;
            }
            System.out.println(res%10);
        }
    }
}