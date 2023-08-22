// 5. 最长回文子串
#include "../def.h"

// DP
// 动态规划关键是找到 初始状态 和 状态转移方程

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }

        int maxLen = 1;
        int begin = 0;

        // dp[i][j] 表示 s[i..j] 是否是回文串
        vector<vector<int>> dp(n, vector<int>(n));

        // 初始化
        for (int i=0; i<n; i++) {
            dp[i][i] = true;
        }

        // 递推开始
        // 先枚举子串长度
        for (int L=2; L<=n; L++) {
            // 枚举左边界，左边界的上限设置可以宽松一些
            for (int i=0; i<n; i++) {
                // 右边界
                int j = L + i - 1;
                if (j >= n) {
                    break;
                }

                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                // 判断结果
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }

        return s.substr(begin, maxLen);
    }
};

// 中心扩散法
// 遍历每一个位置，以此为中心，两边扩散直到不是回文串
