// 139. 单词拆分
#include "../def.h"

// DP
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDictSet;
        for (auto x : wordDict) {
            wordDictSet.insert(x);
        }

        vector<bool> dp(s.size()+1);
        dp[0] = true;

        for (int i=1; i<=s.size(); i++) {
            for (int j=0; j<i; j++) {
                if (dp[j] && wordDictSet.find(s.substr(j, i-j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
        // 回溯
    }
};

// Trie
