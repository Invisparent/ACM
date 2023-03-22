import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner ivsScan = new Scanner(System.in);
        String str = ivsScan.next();
        char ch = str.charAt(0);
        System.out.println((char) (ch + 'A' - 'a'));
    }
}
