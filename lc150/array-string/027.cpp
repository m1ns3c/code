// 68. 文本左右对齐
#include "../def.h"

// 贪心

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();

        vector<string> res;

        int line = 0;
        int count = 0;
        int i=0;
        while (i<n) {
            line += words[i].size();
            count++;
            i++;

            // 溢出
            if (line + (count-1) > maxWidth) {
                // 回退
                i--;
                line -= words[i].size();
                count--;

                // 处理行
                res.push_back(procLine(words, count, i, line, maxWidth));
                count = 0;
                line = 0;
            }
        }
        if (line) {
            res.push_back(procLine(words, count, i, line, maxWidth));
        }
        return res;
    }

    string procLine(vector<string>& words, int count, int end, int line, int maxWidth) {
        string res;
        int space = maxWidth - line;
        int rem = 0, gap = 0;
        if (count == 1) {
            gap = space;
        } else if (end == words.size()) {
            // last
            gap = 1;
        } else {
            rem = space % (count - 1);
            gap = space / (count - 1);
        }

        for (int j=end-count; j<end; j++) {
            res += words[j];
            if (space >= gap) {
                res += std::string(gap, ' ');
                space -= gap;
            }
            if (space && rem) {
                res += ' ';
                rem--;
                space--;
            }
        }

        if (space) {
            res += std::string(space, ' ');
        }

        return res;
    }
};