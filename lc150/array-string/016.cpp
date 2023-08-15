// 238. 除自身以外数组的乘积
#include "../def.h"

// 左右1/2列表额外空间

// 两次往返遍历

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);

        for (int i=1; i<n; i++) {
            answer[i] = answer[i-1] * nums[i-1];
        }

        int right = 1;
        for (int i=n-1; i>=0; i--) {
            int left = answer[i];
            answer[i] = left * right;
            right *= nums[i];
        }
        return answer;
    }
};