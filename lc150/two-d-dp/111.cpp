// 63. 不同路径 II
#include "../def.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                if (i == 1 && j == 1) {
                    dp[i][j] = !obstacleGrid[i-1][j-1];
                    continue;
                }
                if (obstacleGrid[i-1][j-1]) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};

// 滚动数组
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<int> dp(n);

        dp[0] = (obstacleGrid[0][0] == 0);
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0; // 当前列
                    continue;
                }
                if (j - 1 >= 0 && obstacleGrid[i][j-1] == 0) {
                    // dp[j] 即为上方 i-1 行的值
                    // dp[j-1] 为左侧 j-1 列的值
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp.back();
    }
};