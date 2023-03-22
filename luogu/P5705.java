import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner ivsScan = new Scanner(System.in);
        String str = ivsScan.next();
        int x = str.length();
        --x;
        while (x >= 0) {
            System.out.print(str.charAt(x));
            --x;
        }
    }
}
