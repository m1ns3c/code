// 128. 最长连续序列
#include "../def.h"



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;

        for (const int& num : nums) {
            num_set.insert(num);
        }

        int maxLen = 0;

        for (const int& num : num_set) {
            if (!num_set.count(num-1)) {
                int curNum = num;
                int curStreak = 1;

                while (num_set.count(curNum + 1)) {
                    curNum += 1;
                    curStreak += 1;
                }

                maxLen = max(maxLen, curStreak);
            }
        }

        return maxLen;
    }
};