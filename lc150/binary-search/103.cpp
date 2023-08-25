// 74. 搜索二维矩阵
#include "../def.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // m*n 可以转成 一维数组
        // 一维有序数组的搜索
        // 二分 O(logN)

        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int right = m * n - 1;

        while (left <= right) {
            int mid = (right + left) >> 1;
            int i = mid / n;
            int j = mid % n;
            if (matrix[i][j] > target) {
                right = mid - 1;
            } else if (matrix[i][j] < target) {
                left = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};