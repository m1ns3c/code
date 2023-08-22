// Knuth-Morris-Pratt
// O(n+m)

// next
// kmp

// lps
// ABC 的前缀 "", "A", "AB", "ABC"
// Proper prefixes 是 "","A", "AB"
// 后缀是 "", "C", "BC", "ABC"

// both prefix and suffix

// lps[i] = the longest proper prefix of pat[0..i]
// which is also a suffix of pat[0..i]

// 算法
// lps[0] = len = 0
// 如果 pat[len] 和 pat[i] 匹配，len+1，赋值给 lps[i]
// 否则，len 如果不为 0，更新 len = lps[len-1]
#include <bits/stdc++.h>
using namespace std;

void getLPS(char *pat, int m, int *lps) {
    // previous longest prefix suffix
    int len = 0;
    lps[0] = 0; // always 0

    int i = 1;
    while (i < m) {
        if (pat[len] == pat[i]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }            
        }
    }
}

void kmp(char* pat, char* txt) {
    int m = strlen(pat);
    int n = strlen(txt);

    int lps[m];

    getLPS(pat, m, lps);

    int i = 0;  // index of txt
    int j = 0;  // index of pat
    while ((n - i) >= (m - j)) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }

        if (j == m) {
            // found index, i - j
            j = lps[j - 1];
        } else if (i < n && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i = i + 1;
            }
        }
    }
}
