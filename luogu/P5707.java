import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner ivsScan = new Scanner(System.in);
        int a = ivsScan.nextInt();
        int b = ivsScan.nextInt();

        int t = 1910;
        t -= a / b;
        if (a % b != 0)
            --t;
        t %= 1440;

        int h = t / 60, m = t % 60;
        System.out.printf("%02d:%02d%n", h, m);
    }
}
