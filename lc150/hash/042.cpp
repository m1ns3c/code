// 383. 赎金信
#include "../def.h"

// 哈希

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> m(26, 0);

        for (int i=0; i<magazine.size(); i++) {
            ++m[magazine[i]-'a'];
        }

        for (int i=0; i<ransomNote.size(); i++) {
            if (--m[ransomNote[i]-'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};