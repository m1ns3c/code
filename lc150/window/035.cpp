// 30. 串联所有单词的子串
#include "../def.h"

// 滑动窗口

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int m = words.size();
        int n = words[0].size();
        int ls = s.size();

        vector<int> res;

        for(int i=0; i<n && i + m * n <= ls; i++) {
            unordered_map<string,int> differ;
            for (int j=0; j<m; j++) {
                ++differ[s.substr(i+j*n, n)];
            }

            for (int k=0; k<m; k++) {
                if (--differ[words[k]] == 0) {
                    differ.erase(words[k]);
                }
            }

            for (int start = i; start < ls - m * n + 1; start += n) {
                if (start != i) {
                    string word = s.substr(start + (m - 1) * n, n);
                    if (++differ[word] == 0) {
                        differ.erase(word);
                    }

                    word = s.substr(start - n, n);
                    if (--differ[word] == 0) {
                        differ.erase(word);
                    }
                }
                if (differ.empty()) {
                    res.emplace_back(start);
                }
            }
        }
        return res;
    }
};