import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner ivsScan = new Scanner(System.in);
        double a = ivsScan.nextDouble();
        int b = ivsScan.nextInt();
        System.out.printf("%.3f\n%d", a / b, 2 * b);
    }
}
