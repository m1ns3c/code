// 26. 删除有序数组中的重复项
#include "def.h"

// 双指针

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=0;
        while (j < nums.size()) {
            if (nums[j] == nums[i]) {
                j++;
            } else {
                nums[++i] = nums[j++];
            }
        }
        return i+1;
    }
};