// 36. 有效的数独
#include "../def.h"

// 矩阵一次遍历

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 稀疏矩阵 (i, j, x)
        vector<vector<int>> res(3, vector<int>(9, 0));

        for (int i=0;i<board.size();i++) {
            for (int j=0; j<board[i].size(); j++) {
                // row res[0][i] -> i
                // col res[1][j] -> j
                // square res[2][x] -> x
                if (board[i][j] == '.') {
                    continue;
                }

                int t = board[i][j] - '0';
                // 行
                if ((res[0][i] & 1 << t) == 0) {
                    res[0][i] |= 1 << t;
                } else {
                    return false;
                }
                // 列
                if ((res[1][j] & 1 << t) == 0) {
                    res[1][j] |= 1 << t;
                } else {
                    return false;
                }
                // 方形区域
                if ((res[2][i/3*3+j/3] & 1 << t) == 0) {
                    res[2][i/3*3+j/3] |= 1 << t;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};