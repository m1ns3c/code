// 34. 在排序数组中查找元素的第一个和最后一个位置
#include "../def.h"

// 二分+队列
class Solution {
public:
    int bs(vector<int> &nums, int target, int left, int right) {
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (target == nums[mid]) {
                return mid;
            } else if (target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        int n = nums.size();
        if (!n) {
            return {-1, -1};
        }
        int left = n, right = -1;
        queue<pair<int, int>> q;
        q.push({0, n - 1});
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int mid = bs(nums, target, t.first, t.second);
            if (mid >= 0) {
                left = min(mid, left);
                right = max(mid, right);
                q.push({t.first, mid - 1});
                q.push({mid + 1, t.second});
            }
        }
        if (left > right) {
            return {-1, -1};
        }
        return {left, right};
    }
};