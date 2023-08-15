// 88. 合并两个有序数组

// 逆序+双指针

#include "../def.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 倒序处理
        int i = m-1, j = n-1, k = m+n-1;

        while (i>=0 && j>=0) {
            if (nums2[j] >= nums1[i]) {
                nums1[k--] = nums2[j--];
            } else {
                nums1[k--] = nums1[i--];
            }
        }

        // nums2 剩余数
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};