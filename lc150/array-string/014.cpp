// 274. H 指数
#include "../def.h"

// 计数排序

// 排序

// 
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int sum = 0, count;
        for (int i=0; i<citations.size(); i++) {
            sum += citations[i];
        }

        // 大数开方
        int max = floor(sqrt(sum));

        while (max) {
            count = 0;
            for (int i=0; i<citations.size(); i++) {
                if (citations[i] >= max) {
                    count++;
                }
            }
            if (count >= max) {
                break;
            }
            max--;
        }
        return max;
    }
};

// 二分查找
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int start = 0, end = n;
        int count, mid;

        while (start < end) {
            mid = (start + end + 1) >> 1;
            count = 0;
            for (int i=0; i<n; i++) {
                if (citations[i] >= mid) {
                    count++;
                }
            }
            if (count >= mid) {
                start = mid;
            } else {
                end = mid-1;
            }
        }
        
        return start;
    }
};
