//
// Created by daniel.yyf on 2017/8/29.
//
#include "iostream"

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        int *dp = new int[m + 1];
        for (int i = 0; i <= m; i++) {
            dp[i] = i;
        }
        for (int i = 1; i <= n; i++) {
            int v1, v2;
            for (int j = 0; j <= m; j++) {
                if (j == 0) {
                    dp[j] = i;
                    v2 = i - 1;
                    continue;
                }
                v1 = dp[j];
                int deleteNum = dp[j] + 1;
                int insertNum = dp[j - 1] + 1;
                int replaceNum = v2 + (word1[i - 1] == word2[j - 1] ? 0 : 1);
                dp[j] = min(min(deleteNum, insertNum), replaceNum);
                v2 = v1;
            }
        }
        return dp[m];
    }
};

//class Solution {
//public:
//    int minDistance(string word1, string word2) {
//        int n = word1.size(), m = word2.size();
//        int *dp = new int[(n + 1) * (m + 1)];
//        for (int i = 0; i <= n; i++) {
//            dp[(m + 1) * i] = i;
//        }
//        for (int i = 0; i <= m; i++) {
//            dp[i] = i;
//        }
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= m; j++) {
//                int deleteNum = dp[(i - 1) * (m + 1) + j] + 1;
//                int insertNum = dp[i * (m + 1) + j - 1] + 1;
//                int replaceNum = dp[(i - 1) * (m + 1) + j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1);
//                dp[i * (m + 1) + j] = min(min(deleteNum, insertNum), replaceNum);
//            }
//        }
//        return dp[n * (m + 1) + m];
//    }
//};