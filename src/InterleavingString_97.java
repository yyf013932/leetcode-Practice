import java.util.*;

/**
 * Created by daniel.yyf on 2017/7/25.
 */
public class InterleavingString_97 {

    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1.length() + s2.length() != s3.length())
            return false;
        int n = s1.length(), m = s2.length();
        boolean[] dp = new boolean[m + 1];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 && j == 0) {
                    dp[j] = true;
                } else if (i == 0) {
                    dp[j] = dp[j - 1] && s2.charAt(j - 1) == s3.charAt(j - 1);
                } else if (j == 0) {
                    dp[j] = dp[j] && s1.charAt(i - 1) == s3.charAt(i - 1);
                } else {
                    dp[j] = dp[j] && s1.charAt(i - 1) == s3.charAt(i + j - 1) || dp[j - 1] && s2.charAt(j - 1) == s3.charAt(i + j - 1);
                }
            }
        }

        return dp[m];
    }

    public static void main(String[] args) {
        InterleavingString_97 interleavingString_97 = new InterleavingString_97();

        boolean re = interleavingString_97.isInterleave("aba","bac","abbaac");

        System.out.println(re);
    }
}
