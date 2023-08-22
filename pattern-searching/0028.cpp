class Solution {
public:
    void getLPS(string p, vector<int>& lps) {
        int n = p.size();
        int len = 0, i = 1;
        lps[0] = 0;

        while (i < n) {
            if (p[i] == p[len]) {
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

    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int n1 = needle.size();

        vector<int> lps(n1);
        getLPS(needle, lps);

        // KMP
        int i=0, j=0;
        while ((n - i) >= (n1 - j)) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == n1) {
                return i - j;
            }

            if (i < n && haystack[i] != needle[j]) {
                if (j > 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return -1;
    }

    void getNext(string p, vector<int>& next) {
        int n = p.size();
        int i=0, j=1;
        next[0] = 0;

        while (j < n) {
            while (i > 0 && p[i] != p[j]) {
                i = next[i-1];
            }
            
            if (p[i] == p[j]) {
                i++;
            }

            next[j++] = i;
        }
    }

    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int n1 = needle.size();

        vector<int> next(n1, 0);
        getNext(needle, next);

        // KMP
        int i=0, j=0;
        while (i < n) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j-1];
            }

            if (haystack[i] == needle[j]) {
                j++;
            }
            
            i++;
            if (j == n1) {
                return i-j;
            }
        }
        
        return -1;
    }
};