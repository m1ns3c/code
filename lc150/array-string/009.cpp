// 189. 轮转数组
#include "../def.h"

// 1. 额外数组
// 2. 环状替换
// 3. 数组翻转

class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (end > start) {
            int t = nums[end];
            nums[end] = nums[start];
            nums[start] = t;
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n; // 取模，右轮一周等于原数组，否则会溢出

        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1); 
    }
};