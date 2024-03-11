// 153. 寻找旋转排序数组中的最小值
#include "../def.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;
        if (nums[left] <= nums[right]) {
            return nums[left];
        }
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[0] <= nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return nums[left]; // 结果 (right, left)
    }
};