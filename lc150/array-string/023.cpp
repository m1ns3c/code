// 14. 最长公共前缀
#include "../def.h"

// 横向扫描

// 纵向扫描

// 分治

// 二分查找

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        string prefix = strs[0];
        for (int i=1; i<strs.size(); i++) {
            prefix = commonPrefix(prefix, strs[i]);
            if (prefix.empty()) {
                break;
            }
        }
        return prefix;
    }

    string commonPrefix(string str1, string str2) {
        int len = min(str1.size(), str2.size());
        int i = 0;
        while (i < len && str1[i] == str2[i]) {
            i++;
        }

        return str1.substr(0, i);
    }
};