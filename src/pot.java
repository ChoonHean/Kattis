import java.util.*;
public class pot{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int res = 0;
        for (int i = n; n > 0; n--){
            int a = sc.nextInt();
            int b = a/10;
            int c = a%10;
            res += Math.pow(b,c);
        }
        System.out.println(res);
    }
}
