// 45. 跳跃游戏 II
#include "../def.h"

// 贪心

// 反向查找 O(n^2)
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int pos = n-1;
        int steps = 0;

        while (pos > 0) {
            for (int i=0; i<pos; i++) {
                if (i + nums[i] >= pos) {
                    pos = i;
                    steps++;
                    break;
                }
            }
        }
        return steps;   
    }
};

// 正向查找
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxPos = 0, end = 0;
        int steps = 0;

        for (int i=0; i<n-1; i++) {
            if (maxPos >= i) {
                maxPos = max(maxPos, i+nums[i]);

                if (i == end) {
                    end = maxPos;
                    steps++;
                }
            }
        }
        return steps;
    }
};