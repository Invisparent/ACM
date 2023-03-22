import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner ivsScan = new Scanner(System.in);
        String str = ivsScan.nextLine();
        char ch = str.charAt(0);
        System.out.println("  " + ch);
        System.out.println(" " + ch + ch + ch);
        System.out.println("" + ch + ch + ch + ch + ch);
    }
}
