// 169. 多数元素
#include "../def.h"

// 1. 哈希表
// 2. 排序，中位数
// 3. 随机化
// 4. 分治
// 5. Boyer-Moore 投票算法

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0], count = 1;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] == candidate) {
                ++count;
            } else if (--count < 0) {
                candidate = nums[i];
                count = 1;
            }
        }

        return candidate;
    }
};