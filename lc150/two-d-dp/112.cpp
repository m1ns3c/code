// 97. 交错字符串
#include "../def.h"

// DP O(m*n)
// dp[i][j] s1 的前 i 个字符与 s2 的前 j 个字符组成 s3 的 前 i+j 个字符
// dp[i][j] |= dp[i-1][j] && s1[i-1] == s3[i+j-1]
// dp[i][j] |= dp[i][j-1] && s2[j-1] == s3[i+j-1]
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();

        if (n1 + n2 != n3) {
            return false;
        }

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, false));
        dp[0][0] = true;

        for (int i=0; i<=n1; i++) {
            for (int j=0; j<=n2; j++) {
                int p = i + j - 1;
                if (i > 0) {
                    dp[i][j] |= (dp[i-1][j] && s1[i-1] == s3[p]);
                }
                if (j > 0) {
                    dp[i][j] |= (dp[i][j-1] && s2[j-1] == s3[p]);
                }
            }
        }

        return dp[n1][n2];
    }
};

// 滚动数组优化 O(m)
// 第 i 行只跟 i-1 行相关
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();

        if (n1 + n2 != n3) {
            return false;
        }

        vector<int> dp(n2+1, false);
        dp[0] = true;

        for (int i=0; i<=n1; i++) {
            for (int j=0; j<=n2; j++) {
                int p = i + j - 1;
                if (i > 0) {
                    // dp[j] |= (dp[j] && s1[i-1] == s3[p]); // 错误
                    dp[j] &= s1[i-1] == s3[p];
                }
                if (j > 0) {
                    dp[j] |= (dp[j-1] && s2[j-1] == s3[p]);
                }
            }
        }

        return dp[n2];
    }
};