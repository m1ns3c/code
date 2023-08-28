// 15. 三数之和
#include "../def.h"

// 排序+双指针
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i=0; i<n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int k = n - 1;
            int target = -nums[i];

            for (int j=i+1; j<n; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) {
                    continue;
                }

                while (j<k && nums[j] + nums[k] > target) {
                    --k;
                }

                if (j == k) {
                    break;
                }

                if (nums[j] + nums[k] == target) {
                    res.push_back({nums[i],nums[j],nums[k]});
                }
            }
        }
        return res;
    }
};
