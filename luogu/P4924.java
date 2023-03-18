import java.util.Scanner;

public class Main {
    private static void rotate(int i, int j, int r, int d) {
        int len = 2 * r + 1;
        int begI = i - r, begJ = j - r, endI = i + r, endJ = j + r;

        if (d == 0)
            for (int x = 0; x < len; ++x)
                for (int y = 0; y < len; ++y)
                    newMatrix[begI + y][endJ - x] = matrix[begI + x][begJ + y];
        else
            for (int x = 0; x < len; ++x)
                for (int y = 0; y < len; ++y)
                    newMatrix[endI - y][begJ + x] = matrix[begI + x][begJ + y];

        for (int t = begI; t <= endI; ++t)
            System.arraycopy(newMatrix[t], begJ, matrix[t], begJ, len);
    }

    public static void main(String[] args) {
        Scanner ivsScan = new Scanner(System.in);
        int n = ivsScan.nextInt();
        ivsScan.nextInt();

        matrix = new int[n + 2][n + 2];
        int x = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                matrix[i][j] = x;
                ++x;
            }

        newMatrix = new int[n + 2][n + 2];

        while (ivsScan.hasNextInt()) {
            int a = ivsScan.nextInt();
            int b = ivsScan.nextInt();
            int c = ivsScan.nextInt();
            int d = ivsScan.nextInt();
            rotate(a, b, c, d);
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                System.out.print(matrix[i][j]);
                System.out.print(' ');
            }
            System.out.println();
        }
    }

    static private int[][] matrix;
    static private int[][] newMatrix;
}
