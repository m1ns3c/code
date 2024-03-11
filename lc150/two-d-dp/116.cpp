// 123. 买卖股票的最佳时机 III
#include "../def.h"

// DP
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();

        int buy1 = -prices[0], sell1 = 0;
        int buy2 = -prices[0], sell2 = 0;
        for (int i=1; i<n; i++) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);

            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return sell2;
    }
};

// BF Naive
class Solution {
public:
    int maxProfitNum = 0;
    void backtrack(vector<vector<int>> &profit, int m, int i, int j, int level, int temp) {
        // 记录
        if (temp > maxProfitNum) {
            maxProfitNum = temp;
        }
        // 剪枝
        if (level > 2 || i >= m || j >= m) {
            return;
        }
        // 跳过
        backtrack(profit, m, i, j, level + 1, temp);
        // 选择
        for (int l = j; l < m; l++) {
            for (int k = j; k < m; k++) {
                temp += profit[i][j];;
                backtrack(profit, m, l + 1, k + 2, level + 1, temp);
                temp -= profit[i][j];;
            }
        }
    }

    int maxProfit(vector<int> &prices) {
        // 暴力破解思路
        int m = prices.size();
        vector<vector<int>> profit(m, vector<int>(m));
        for (int i = 0; i < m - 1; i++) {
            for (int j = i + 1; j < m; j++) {
                // i 天买入 j 天卖出，收益
                profit[i][j] = prices[j] - prices[i];
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                backtrack(profit, m, i, j, 1, 0);
            }
        }
        return maxProfitNum;
    }
};