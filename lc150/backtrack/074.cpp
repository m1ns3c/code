// 46. 全排列
#include "../def.h"

// 交换代替去重数组
class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, int k, int n) {
        if (k == n) {
            res.push_back(nums);
            return;
        }

        for (int i=k; i<n; i++) {
            swap(nums[i], nums[k]);
            backtrack(nums, k + 1, n);
            swap(nums[i], nums[k]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0, nums.size());
        return res;
    }
};

// 去重数组
class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    void backtrack(vector<int>& nums, int k, int n) {
        if (k == n) {
            // res.push_back(nums);
            res.push_back(temp);
            return;
        }

        for (int i=0; i<n; i++) {
            // 重复检测
            if (std::find(temp.begin(), temp.end(), nums[i]) != temp.end()) {
                continue;
            }
            temp.push_back(nums[i]);
            // swap(nums[i], nums[k]);
            backtrack(nums, k + 1, n);
            // swap(nums[i], nums[k]);
            temp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0, nums.size());
        return res;
    }
};

// 错误（全排列，可以重复选择）（适合于互斥情况）
class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;

    int n;
    void dfs(vector<int>& nums, int k) {
        // 剪枝
        if (temp.size() + (n - k + 1) < n) {
            return;
        }

        // 记录结果
        if (temp.size() == n) {
            res.push_back(temp);
            return;
        }

        // 选择
        temp.push_back(nums[k]);
        dfs(nums, k + 1);

        // 不选择
        temp.pop_back();
        dfs(nums, k + 1);
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        dfs(nums, 0);
        return res;
    }
};