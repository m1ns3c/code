// 221. 最大正方形
#include "../def.h"

// DP
// 1.最优解（背包）- 最优子结构
// 2.计数（路径和）- 子问题的方案数
class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxSide = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        // 关键
                        dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
                    }
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        return maxSide * maxSide;
    }
};

// BP 暴力破解
class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxSide = 0; // 最大边
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 起始点位置有效
                if (matrix[i][j] == '1') {
                    // 起始点边=1
                    maxSide = max(maxSide, 1);
                    // 边长度递增
                    for (int l = 1; l<m-i&&l<n-j; l++) {
                        // 退出标志
                        bool flag = true;
                        // 终点
                        if (matrix[i + l][j + l] == '0') {
                            break;
                        }
                        // 判断列和行是否都为1
                        for (int y = 0; y < l; y++) {
                            // matrix[i + l][j + y] 行
                            // matrix[i + y][j + l] 列
                            if (matrix[i + l][j + y] == '0' || matrix[i + y][j + l] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        if (flag) {
                            maxSide = max(maxSide, l + 1);
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        return maxSide * maxSide;
    }
};