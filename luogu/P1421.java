import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner ivsScan = new Scanner(System.in);
        int a = ivsScan.nextInt();
        int b = ivsScan.nextInt();
        int r = a * 10 + b;
        int res = r / 19;
        System.out.println(res);
    }
}
