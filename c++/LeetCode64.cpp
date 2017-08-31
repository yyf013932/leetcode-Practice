//
// Created by daniel.yyf on 2017/8/30.
//
#include <vector>
#include "iostream"

using namespace std;

#define INT_MAX 0x7FFFFFFF

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int *dp = new int[n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[j] = grid[0][0];
                    continue;
                }
                int interval = (i == 0 ? INT_MAX : dp[j]);
                int horizontal = (j == 0 ? INT_MAX : dp[j - 1]);
                dp[j] = min(interval, horizontal) + grid[i][j];
            }
        }
        return dp[n - 1];
    }
};
