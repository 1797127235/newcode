import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n1 = sc.nextInt();
        String c1 = sc.next();
        int n2 = sc.nextInt();
        String c2 = sc.next();

        if (n1 > n2) {
            System.out.println("Yes");
        } else if (n1 < n2) {
            System.out.println("No");
        } else {
            int cmp = c1.compareTo(c2);
            if (cmp < 0) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
    }
}
