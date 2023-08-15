// 122. 买卖股票的最佳时机 II
#include "../def.h"

// DP

// 状态方程：今天最大盈利 = fmax(昨天最大盈利，昨天最大盈利+今天盈利);

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n, 0);
        
        int max = 0;

        dp[0] = 0;
        for (int i=1; i<n; i++) {
            dp[i] = fmax(dp[i-1], dp[i-1]+prices[i]-prices[i-1]);
            if (dp[i] > max) {
                max = dp[i];
            }
        }

        return max;
    }
};