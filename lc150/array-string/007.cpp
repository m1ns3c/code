// 80. 删除有序数组中的重复项 II
#include "../def.h"

// 双指针
// 起始 - 结束位置界定

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, j = 2; // 起始位置
        int n = nums.size();
        while (i < n && j < n) {
            if (nums[j] == nums[i] && nums[j] == nums[i-1]) {
                j++;
                continue;
            }
            nums[++i] = nums[j++];
        }
        return n > 1 ? i + 1 : n; // 元素数 >= 2
    }
};
