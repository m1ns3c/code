// 57. 插入区间
#include "../def.h"

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        int left = newInterval[0];
        int right = newInterval[1];

        bool placed = false;

        for (int i=0; i<intervals.size(); i++) {
            if (intervals[i][0] > right) {
                if (!placed) {
                    res.push_back({left, right});
                    placed = true;
                }
                res.push_back(intervals[i]);
            } else if (intervals[i][1] < left) {
                res.push_back(intervals[i]);
            } else {
                left = min(left, intervals[i][0]);
                right = max(right, intervals[i][1]);
            }
        }

        if (!placed) {
            res.push_back({left, right});
        }
        return res;
    }
};