//
#include "../def.h"

// 双指针

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int max = 0, t;
        int i=0, j, flag, mj;
        while (i<n) {
            j = n-1;
            mj = -1;
            while (j>i) {
                if (height[j] > mj) {
                    mj = height[j];
                } else if (height[j] < mj) {
                    j--;
                    continue;
                }

                t = (j-i) * min(height[i], height[j]);
                if (t > max) {
                    max = t;
                }

                if (height[j] > height[i]) {
                    break;
                }
                j--;
            }
            i++;
        }
        return max;
    }
};