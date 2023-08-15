// 73. 矩阵置零
#include "../def.h"

// 两个数组记录行与列是否为0

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> row;
        vector<int> col;

        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (!matrix[i][j]) {
                    row.emplace_back(i);
                    col.emplace_back(j);
                }
            }
        }

        for (int i=0;i<row.size(); i++) {
            for (int j=0;j<m;j++) {
                matrix[row[i]][j] = 0;
            }
        }

        for (int i=0;i<col.size(); i++) {
            for (int j=0;j<n;j++) {
                matrix[j][col[i]] = 0;
            }
        }
    }
};

// 使用数组的第一行/第一列记录，增加两个标志，记录第一行/第一列是否含0

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int firstRowZero = false;
        int firstColZero = false;

        // 第一行
        for (int j=0;j<m;j++) {
            if (!matrix[0][j]) {
                firstRowZero = true;
            }
        }

        // 第一列
        for (int i=0;i<n; i++) {
            if (!matrix[i][0]) {
                firstColZero = true;
            }
        }

        for (int i=1;i<n;i++) {
            for (int j=1;j<m;j++) {
                if (!matrix[i][j]) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i=1;i<n;i++) {
            if (!matrix[i][0]) {
                for (int j=1; j<m; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int i=1;i<m;i++) {
            if (!matrix[0][i]) {
                for (int j=1; j<n; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
        
        if (firstColZero) {
            for (int i=0;i<n; i++) {
                matrix[i][0] = 0;
            }
        }

        if (firstRowZero) {
            for (int i=0;i<m; i++) {
                matrix[0][i] = 0;
            }
        }
    }
};