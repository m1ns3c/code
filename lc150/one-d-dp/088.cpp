// 198. 打家劫舍
#include "../def.h"

// DP
class Solution {
public:
    int rob(vector<int>& nums) {
        // 每间房屋分为拿和不拿
        // 不拿为0
        // 拿 总和+本次金额

        int n = nums.size();
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = nums[0];

        int i=2;
        while (i <= n) {
            dp[i] = max(dp[i-1]+0, dp[i-2]+ nums[i-1]);
            i++;
        }

        return dp[n];
    }
};