// 918. 环形子数组的最大和
#include "../def.h"

// 1.DP
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int gmax = nums[0];
        for (int i=0; i<n; i++) {
            int pre = 0, res = nums[i];
            int j = i;
            while (j - i != n) {
                pre = fmax(pre + nums[j % n], nums[j % n]);
                res = fmax(res, pre);
                j++;
            }
            gmax = fmax(res, gmax);
        }
        return gmax;
    }
};

// 2.取反
// 最大区间 nums[0:i] + nums[j:n]
// 反向获取，取 nums[i:j] 最小的和区间
// sum - minRes
// 如果 sum < 0, 返回 maxRes
