import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner ivsScan = new Scanner(System.in);
        int a = ivsScan.nextInt();
        int b = ivsScan.nextInt();
        int c = ivsScan.nextInt();
        int res = (a * 2 + b * 3 + c * 5) / 10;

        System.out.println(res);
    }
}
