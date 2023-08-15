// 39. 组合总和
#include "../def.h"

class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    void dfs(vector<int>& candidates, int index, int target) {
        // 无数可选
        if (index == candidates.size()) {
            return;
        }
        if (target == 0) {
            res.push_back(temp);
            return;
        }

        // 直接跳过
        dfs(candidates, index+1, target);

        // 选择当前数
        if (target - candidates[index] >= 0) {
            temp.push_back(candidates[index]);
            dfs(candidates, index, target-candidates[index]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, target);
        return res;
    }
};