// 121. 买卖股票的最佳时机
#include "../def.h"

// DP

//  【错误思路】状态方程：盈利 = 昨天卖出的盈利+今天盈利【错误】

// 状态方程：最低点 = min(昨天最低点，今天价格）
// 今天最大盈利 = 今天价格 - 最低点

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max = -1, min, t;

        vector<int> dp(n+1, 0);
        dp[0] = prices[0];

        for (int i=1; i<n; i++) {
            dp[i] = dp[i-1] < prices[i] ? dp[i-1] : prices[i];
            max = (prices[i] - dp[i]) > max ? prices[i] - dp[i] : max;
        }
        return max > 0 ? max : 0;
    }
};

