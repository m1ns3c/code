// 28. 找出字符串中第一个匹配项的下标
#include "../def.h"

// KMP
// 对匹配串做处理

class Solution {
public:
    void getNext(string p, vector<int>& next) {
        int n = p.size();
        int i=0, j=1;
        next[0] = 0;

        while (j < n) {
            while (i > 0 && p[i] != p[j]) {
                i = next[i-1];
            }
            
            if (p[i] == p[j]) {
                i++;
            }

            next[j++] = i;
        }
    }

    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int n1 = needle.size();

        vector<int> next(n1, 0);
        getNext(needle, next);

        int i=0, j=0;
        while (i < n) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j-1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            i++;
            if (j == n1) {
                return i-j;
            }
        }
        
        return -1;
    }
};
