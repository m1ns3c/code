// 344. 反转字符串
#include "def.h"

// 双指针

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size()-1;

        while (left < right) {
            char t = s[left];
            s[left++] = s[right];
            s[right--] = t;
        }
    }
};