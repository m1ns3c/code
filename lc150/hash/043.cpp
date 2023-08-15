// 49. 字母异位词分组

#include "../def.h"

// 按计数转正序字母序作为 key

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        vector<vector<string>> res;

        for (int i=0; i<strs.size(); i++) {
            vector<int> tm(26,0);
            for (int j=0; j<strs[i].size(); j++) {
                tm[strs[i][j] - 'a']++;
            }

            // 正序
            string key = "";
            for (int j=0; j<26; j++) {
                key += std::string(tm[j], 'a'+j);
            }

            mp[key].push_back(strs[i]);
        }

        for (auto it = mp.begin(); it != mp.end(); it++) {
            res.push_back(it->second);
        }

        return  res;
    }
};