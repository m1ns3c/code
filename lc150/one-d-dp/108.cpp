// 剑指 Offer 10- II. 青蛙跳台阶问题
#include "../def.h"

// DP
class Solution {
public:
    int numWays(int n) {
        // 1.数组元素意思 到达当前台阶总跳法
        // 2.元素关系式 dp[i] = dp[i-1] + dp[i-2]
        // 3.初始值 dp[0] = 1, dp[1] = 1;
        if (n < 2) {
            return 1;
        }

        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i=2; i<=n; i++) {
            dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
        }

        return dp[n];
    }
};

// 双变量
class Solution {
public:
    int numWays(int n) {
        int p = 1;
        int pp = 1;

        if (n < 2) {
            return p;
        }

        for (int i=2; i<=n; i++) {
            int t = (pp + p) % 1000000007;
            pp = p;
            p = t;
        }
        return p;
    }
};