// 162. 寻找峰值
#include "../def.h"

// 1.寻找最大值 O(n)

// 2.迭代爬坡 O(n)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int index = rand() % n;

        auto get = [&](int i) -> pair<int, int> {
            if (i == -1 || i == n) {
                return {0, 0};
            }
            return {1, nums[i]};
        };
        while (!(get(index - 1) < get (index) && get(index) > get(index + 1))) {
            if (get(index) < get(index + 1)) {
                index += 1;
            } else {
                index -= 1;
            }
        }
        return index;
    }
};

// 3.方法二的二分查找优化

