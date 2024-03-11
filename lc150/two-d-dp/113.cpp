// 72. 编辑距离
#include "../def.h"

// DP
// dp[i][j] 字符串1的前 i 个字符 变为 字符串2的前 j 个字符需要的最小操作数
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1));
        dp[0][0] = 0;
        for (int i=0; i<=n; i++) {
            dp[i][0] = i;
        }
        for (int j=1; j<=m; j++) {
            dp[0][j] = j;
        }

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (word1[i-1] == word2[j-1]) {
                    // 当前字符相等，不需要调整
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    // 三个操作中最小到达+1
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
            }
        }
        return dp[n][m];
    }
};