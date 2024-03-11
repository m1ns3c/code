// 33. 搜索旋转排序数组
#include "../def.h"

// 与两端值进行比较
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int index = -1;
        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int mid = (right + left) >> 1;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n-1]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return index;
    }
};