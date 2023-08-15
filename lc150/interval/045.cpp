// 228. 汇总区间
#include "../def.h"

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        int i=0;
        while (i<n) {
            int start = i;
            while (i<n-1 && nums[i]+1 == nums[i+1]) {
                i++;
            }

            if (i == start) {
                res.push_back(to_string(nums[i]));
            } else {
                res.push_back(to_string(nums[start])+"->"+to_string(nums[i]));
            }
            i++;
        }

        return res;
    }
};