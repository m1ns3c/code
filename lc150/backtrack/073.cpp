// 77. 组合
#include "../def.h"

// 枚举
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tv;
    void backtrack(int index, int k, int start, int end) {
        // 结束条件
        if (index == k) {
            res.push_back(tv);
        } else {
            for (int i=start; i<=end; i++) {
                // 重复检测
                if (!tv.empty() && i <= tv.back()) {
                    continue;
                }
                tv.push_back(i);
                backtrack(index+1, k, start, end);
                tv.pop_back();
            }
        }
    }

    vector<vector<int>> combine(int n, int k) {
        // 长度 1~k，每一位 都可以是 [1~n] 组成，不重复
        backtrack(0, k, 1, n); // 0 开始 index
        return res;
    }
};

// 递归 + 剪枝
class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    void dfs(int cur, int n, int k) {
        // 剪枝
        if (temp.size() + (n - cur + 1) < k) {
            return;
        }

        // 记录合法答案
        if (temp.size() == k) {
            res.push_back(temp);
            return;
        }

        // 考虑选择当前位置
        temp.push_back(cur);
        dfs(cur + 1, n, k);

        // 考虑不选择当前位置
        temp.pop_back();
        dfs(cur + 1, n, k);
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return res;
    }
};