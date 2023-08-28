// 120. 三角形最小路径和
#include "../def.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int level = triangle.size();
        int m = triangle[level - 1].size();
        // 可以确定是二维
        // 数组元素的含义：dp[i][j] 到达当前位置的路径和，由于有两条路径，所以选最小和
        // 如何到达当前路径 dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]
        // 数组关系：dp[i][j] =
        // 初始值 dp[0][0] = triangle[0][0];
        // i >= 1, j
        // 限制条件
        vector<vector<int>> dp(level, vector<int>(m, 1000));
        for (int i = 0; i < level; i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                int t = 0;
                if (i > 0) {
                    t = dp[i - 1][j];
                    if (j > 0) {
                        t = min(t, dp[i - 1][j - 1]);
                    }
                }
                dp[i][j] = t + triangle[i][j];
            }
        }
        int minSum = dp[level-1][0];
        for (int i=1; i<dp[level-1].size(); i++) {
            minSum = min(minSum, dp[level-1][i]);
        }
        return minSum;
    }
};


class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int level = triangle.size();
        int m = triangle[level - 1].size();
        
        int minSum = 1000;
        for (int i = 0; i < level; i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                int t = 0;
                if (i > 0) {
                    t = i == j ? 1000 : triangle[i - 1][j];
                    if (j > 0) {
                        t = min(t, triangle[i - 1][j - 1]);
                    }
                }
                triangle[i][j] = t + triangle[i][j];
                if (i == level - 1) {
                    minSum = min(minSum, triangle[i][j]);
                }
            }
        }
        return minSum;
    }
};