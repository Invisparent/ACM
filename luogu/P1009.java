import java.util.*;
import java.math.*;

public class Main {
    static BigInteger ivsFact(int n) {
        BigInteger retVal = new BigInteger("1");
        for (int t = 2; t <= n; ++t)
            retVal = retVal.multiply(new BigInteger(Integer.toString(t)));
        return retVal;
    }

    public static void main(String[] args) {
        Scanner ivsScan = new Scanner(System.in);
        int n = ivsScan.nextInt();
        ivsScan.close();
        BigInteger res = new BigInteger("0");

        for (int t = 1; t <= n; ++t)
            res = res.add(ivsFact(t));

        System.out.println(res);
    }
}
