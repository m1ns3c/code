// 15. 三数之和
#include "../def.h"

// 排序+双指针

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end(), less<int>());
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                break;
            }
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    if ((nums[i] + nums[j] + nums[k]) == 0) {
                        res.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        return res;
    }
};
