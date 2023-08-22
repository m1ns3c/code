// 215. 数组中的第K个最大元素
#include "../def.h"

// 堆排序
class Solution {
public:
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;
        int lc = 2 * i + 1;
        int rc = 2 * i + 2;

        if (lc < n && nums[lc] > nums[largest]) {
            largest = lc;
        }
        if (rc < n && nums[rc] > nums[largest]) {
            largest = rc;
        }

        if (largest != i) {
            swap(nums[largest], nums[i]);
            heapify(nums, n, largest);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i=n / 2 - 1; i>=0; i--) {
            heapify(nums, n, i);
        }

        for (int i=n-1; i>=n-k; i--) {
            swap(nums[i], nums[0]);
            heapify(nums, i, 0);
        }

        return nums[n-k];
    }
};