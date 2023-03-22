import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner ivsScan = new Scanner(System.in);
        int a = ivsScan.nextInt();
        int b = ivsScan.nextInt();
        int c = ivsScan.nextInt();
        int d = ivsScan.nextInt();

        int h = c - a;
        int m = d - b;
        if (m < 0) {
            m += 60;
            --h;
        } else if (m >= 60) {
            h -= m / 60;
            m %= 60;
        }

        System.out.printf("%d %d", h, m);
    }
}
