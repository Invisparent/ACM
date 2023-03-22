import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner ivsScan = new Scanner(System.in);
        int a = ivsScan.nextInt();
        int b = ivsScan.nextInt();
        int c = 314 * a * b * b;
        int d = 2000000 / c;
        if (200000 % c != 0)
            ++d;

        System.out.println(d);
    }
}
