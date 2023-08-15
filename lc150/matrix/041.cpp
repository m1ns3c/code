// 289. 生命游戏
#include "../def.h"

// BF
class Solution {
public:
    vector<pair<int, int>> dir = {
        {-1,-1},
        {-1,0},
        {-1,1},
        {0,-1},
        {0,1},
        {1,-1},
        {1,0},
        {1,1},
    };

    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> res(n, vector<int>(m, -1));

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int count = 0;
                for (int k=0; k<dir.size(); k++) {
                    int x = i+dir[k].first;
                    int y = j+dir[k].second;
                    if (x>=0 && x<n && y>=0 && y<m) {
                        count += board[x][y];
                    }
                }

                if (board[i][j]) {
                    // live
                    if (count < 2 || count > 3) {
                        // die
                        res[i][j] = 0;
                    }
                } else {
                    // died
                    if (count == 3) {
                        // live
                        res[i][j] = 1;
                    } 
                }
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (res[i][j] != -1) {
                    board[i][j] = res[i][j];
                }
            }
        }
    }
};

// 原地 + 额外状态

