// 125. 验证回文串
#include "../def.h"

// 双指针

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();

        int left = 0, right = n-1;

        while (left <= right) {
            while (left < n && !isalnum(s[left])) {
                left++;
            }
            while (right > 0 && !isalnum(s[right])) {
                right--;
            }
            
            if (left>=right) {
                return true;
            }

            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }
        return true;
    }
};