// 392. 判断子序列
#include "../def.h"

// 双指针
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int n1 = t.size();

        int p1 = 0, p2 = 0;
        while (p1 < n && p2 < n1) {
            if (s[p1] == t[p2]) {
                p1++;
            }
            p2++;
        }

        return p1 == n;
    }
};

// DP
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        // DP
        vector<vector<int>> f(m+1, vector<int>(26, 0));

        for (int i=0; i<26; i++) {
            f[m][i] = m;
        }

        for (int i=m-1; i>=0; i--) {
            for (int j=0; j<26; j++) {
                if (t[i] == j+'a') {
                    f[i][j] = i; // 当前位置
                } else {
                    f[i][j] = f[i+1][j]; // 后一个字符 之后的位置
                }
            }
        }

        int add = 0;
        for (int i=0; i<n; i++) {
            if (f[add][s[i] - 'a'] == m) { // 到达尾部
                return false;
            }
            add = f[add][s[i] - 'a'] + 1; // 下一个开始位置
        }
        return true;
    }
};
