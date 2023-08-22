// 70. 爬楼梯
#include "../def.h"

// 一维 DP
class Solution {
public:
    int climbStairs(int n) {
        // n = n-2 + 2
        // n = n-1 + 1
        // 到 i 层有多少种方式

        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;

        int i=2;
        while (i <= n) {
            dp[i] = dp[i-1] + dp[i-2];
            i++;
        }

        return dp[n];
    }
};

// 两数缓存
class Solution {
public:
    int climbStairs(int n) {
        int prev = 1, last = 1;
        int i=2;
        while (i <= n) {
            int t = prev + last;
            prev = last;
            last = t;
            i++;
        }
        return last;
    }
};