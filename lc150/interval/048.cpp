// 452. 用最少数量的箭引爆气球
#include "../def.h"

// 排序 - 贪心 - 交集

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[0] < b[0];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);

        int count = 0;
        int left = points[0][0], right = points[0][1];
        for (int i=0; i<points.size(); i++) {
            if (points[i][0] > right || points[i][1] < left) {
                count++;
                left = points[i][0];
                right = points[i][1];
            } else {
                left = max(left, points[i][0]);
                right = min(right, points[i][1]);
            }
        }

        return ++count;
    }
};