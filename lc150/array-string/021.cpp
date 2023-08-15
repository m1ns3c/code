// 12. 整数转罗马数字
#include "../def.h"

class Solution {
public:
    string intToRoman(int num) {
        string res;
        vector<pair<int, string>> vp = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };

        int n = vp.size(), i=0;
        while (num > 0) {
            if (num >= vp[i].first) {
                num -= vp[i].first;
                res += vp[i].second;
            } else {
                i++; 
            }
        }
        return res;
    }
};
