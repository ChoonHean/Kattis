import java.util.*;
public class autori {
    public static void shorten (String input){
        StringBuilder res = new StringBuilder();
        res.append(input.charAt(0));
        for (int i = 0; i < input.length(); i += 1){
            if (input.charAt(i) == '-'){
                res.append(input.charAt(i + 1));
            }
        }
        System.out.println(res.toString());
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        shorten(sc.nextLine());
        }
    }
