// 135. 分发糖果
#include "../def.h"

// 额外数组
// 两次遍历

// 常数空间遍历

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> left(n, 1);
        for (int i=1; i<n; i++) {
            if (ratings[i] > ratings[i-1]) {
                left[i] = left[i-1] + 1;
            }
        }

        for (int i=n-2; i>=0; i--) {
            if (ratings[i] > ratings[i+1]) {
                left[i] = max(left[i], left[i+1]+1);;
            }
        }

        int sum = 0;
        for (int i=0; i<n; i++) {
            sum += left[i];
        }

        return sum;
    }
};

// 贪心：局部最优

