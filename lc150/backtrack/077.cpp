// 79. 单词搜索
#include "../def.h"

// 回溯

// 约束性问题
// 变量 值域 约束条件

// 迷宫，八皇后
// 对角线：行列之差相等

// 剪枝
class Solution {
public:
    int m, n;
    
    // 4个方向
    vector<pair<int, int>> dir = {
            {1,  0},
            {0,  1},
            {-1, 0},
            {0,  -1},
    };

    bool check(vector<vector<char>> &board, string& word, int i, int j, int k) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k]) {
            return false;
        }
        if (k == word.size() - 1) {
            return true;
        }

        board[i][j] = '\0';

        bool result = false;
        for (int l = 0; l < dir.size(); l++) {
            if (check(board, word, i + dir[l].first, j + dir[l].second, k+1)) {
                result = true;
                break;
            }
        }
        // 恢复
        board[i][j] = word[k];
        return result;
    }

    bool exist(vector<vector<char>> &board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (check(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

// 原始思路
class Solution {
public:
    bool found = false;
    unordered_map<char, bool> mp;
    int m;
    int n;

    // 4个方向
    vector<pair<int, int>> dir = {
            {1,  0},
            {0,  1},
            {-1, 0},
            {0,  -1},
    };

    void backtrack(vector<vector<char>> &board, string word, int x, int y, string temp, vector<vector<int>> visited) {
        // 基线条件
        if (temp == word) {
            found = true;
            return;
        }

        // 剪枝
        if (x < 0 || x >= m || y < 0 || y >= n
            || !mp.count(board[x][y])
            || temp.size() > word.size()
            || visited[x][y]) {
            return;
        }

        for (int i = 0; i < dir.size(); i++) {
            temp.push_back(board[x][y]);
            visited[x][y] = true;
            backtrack(board, word, x + dir[i].first, y + dir[i].second, temp, visited);
            temp.pop_back();
        }
    }

    bool exist(vector<vector<char>> &board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < word.size(); i++) {
            mp[word[i]] = true;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<vector<int>> visited(m, vector<int>(n, false));
                string temp;
                backtrack(board, word, i, j, temp, visited);
            }
        }

        return found;
    }
};