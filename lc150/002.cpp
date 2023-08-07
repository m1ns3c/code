// 27. 移除元素
#include "def.h"

// 双指针

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0, j=0, k;

        while (j < nums.size()) {
            k = nums[j];
            if(k != val) {
                nums[i] = k;
                i++;
            }
            j++;
        }

        return i;
    }
};