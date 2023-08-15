// 17. 电话号码的字母组合
#include "../def.h"

// 回溯
// index == n 为结束条件
// 否则，进行 index + 1 递归

class Solution {
public:
    unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
    };

    void backtrack(string digits, int index, vector<string>& res, string s) {
        if (index == digits.size()) {
            res.push_back(s);
        } else {
            string& t = mp.at(digits[index]);
            for (int i=0; i<t.size(); i++) {
                s.push_back(t[i]);
                backtrack(digits, index+1, res, s);
                s.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) {
            return res;
        }
        string s;
        backtrack(digits, 0, res, s);
        return res;
    }
};