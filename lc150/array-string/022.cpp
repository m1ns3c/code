// 58. 最后一个单词的长度
#include "../def.h"

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();

        while(s[--n] == ' ') {
        }

        int e = n;
        while (e >= 0) {
            if (s[e] == ' ') {
                return n-e;
            }
            e--;
        }
        return n-e;
    }
};