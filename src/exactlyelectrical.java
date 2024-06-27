import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int startX = sc.nextInt();
        int startY = sc.nextInt();
        int endX = sc.nextInt();
        int endY = sc.nextInt();
        int battery = sc.nextInt();
        int result = battery - Math.abs(startX - endX) - Math.abs(startY - endY);
        if (result >= 0 && result % 2 == 0) {
            System.out.println("Y");
        } else {
            System.out.println("N");
        }
    }
}