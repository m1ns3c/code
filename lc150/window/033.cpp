// 209. 长度最小的子数组
#include "../def.h"

// 滑动窗口

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = 0;
        int min = n+1, sum=nums[0];
        
        while (i<=j && j<n) {
            if (sum >= target) {
                if ((j-i+1) < min) {
                    min = j-i+1;
                }
                sum -= nums[i];
                i++;
            } else {
                if (++j < n) {
                    sum += nums[j];
                }
            }
        }
        return min == n+1 ? 0 : min;
    }
};