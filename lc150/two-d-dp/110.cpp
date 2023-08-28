// 64. 最小路径和
#include "../def.h"

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        // 向下 向右
        // dp[i][j] i行 j列 到达当前的最小路径和
        // dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < rows; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for (int i = 1; i < cols; i++) {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        return dp[rows-1][cols-1];
    }
};