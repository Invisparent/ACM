import java.util.Scanner;

public class Main {
    private static int mine(int i, int j) {
        int retVal = 0;
        for (int x = -1; x <= 1; ++x)
            for (int y = -1; y <= 1; ++y)
                if (!(x == 0 && y == 0) && data[i + x][j + y] == '*')
                    ++retVal;

        return retVal;
    }

    public static void main(String[] args) {
        Scanner ivsScan = new Scanner(System.in);
        int m = ivsScan.nextInt(), n = ivsScan.nextInt();

        data = new char[m + 2][n + 2];
        for (int i = 1; i <= m; ++i) {
            String str = ivsScan.next();
            for (int j = 1; j <= n; ++j)
                data[i][j] = str.charAt(j - 1);
        }

        int[][] res = new int[m + 2][n + 2];
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                res[i][j] = mine(i, j);

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j)
                if (data[i][j] == '*')
                    System.out.print('*');
                else
                    System.out.print(res[i][j]);
            System.out.println();
        }
    }

    static char[][] data;
}
