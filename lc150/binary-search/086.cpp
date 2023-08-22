// 35. 搜索插入位置
#include "../def.h"

// 二分
// 下一个位置为l
// 前一个位置为 r

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < target) {
                l = mid+1;
            } else if (nums[mid] > target) {
                r = mid-1;
            } else {
                return mid;
            }
        }
        return l;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1, ans = n;
        while (left <= right) {
            int mid = ((right - left) >> 1) + left;
            if (target <= nums[mid]) {
                ans = mid; // 位置
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};