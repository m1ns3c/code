//
#include "../def.h"

// 1.二分
// 外循环 + 二分查找
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        int i = 0, left, mid, right;
        while (i<n) {
            // 二分查找
            left = i+1;
            right = n-1;    // 左右闭合 [left, right]
            while (left <= right) {
                mid = left + (right - left) / 2;
                if (numbers[i]+numbers[mid] > target) {
                    right = mid - 1;
                } else if (numbers[i]+numbers[mid] < target){
                    left = mid + 1;
                } else {
                    return {i+1, mid+1};
                }
            }
            i++;
        }
        return {-1, -1};
    }
};

// 2.双指针：左右两端分别指针
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        vector<int> res(2);
        int left=0, right=n-1, t;
        while (left < right) {
            t = numbers[left]+numbers[right];
            if (t > target) {
                right--;
            } else if (t < target){
                left++;
            } else {
                res[0] = left+1;
                res[1] = right+1;
                return res;
            }
        }
        return res;
    }
};

// 暴力破解
// 超时：未使用非递减的条件

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        int i = 0, j;
        while (i<n) {
            j = i+1;
            while (j<n) {
                if (numbers[i]+numbers[j] == target) {
                    return {i+1, j+1};
                }
                j++;
            }
            i++;
        }
        return {-1,-1};
    }
};
