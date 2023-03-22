import java.util.Scanner;
import java.lang.Math;

public class Main {
    public static void main(String[] args) {
        Scanner ivsScan = new Scanner(System.in);
        double a = ivsScan.nextDouble();
        double b = ivsScan.nextDouble();
        double c = ivsScan.nextDouble();
        double p = 0.5 * (a + b + c);
        double res = Math.sqrt(p * (p - a) * (p - b) * (p - c));
        System.out.printf("%.1f", res);
    }
}
