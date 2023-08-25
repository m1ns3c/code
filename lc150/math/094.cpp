// 66. 加一
#include "../def.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        int over = 1;
        int t;
        for (int i=n-1; i>=0; i--) {
            t = digits[i] + over;
            over = t / 10;
            digits[i] = t % 10;
        }

        if (over) {
            digits.push_back(0);
            for (int i=n; i>0; i--) {
                digits[i] = digits[i-1];
            }
            digits[0] = 1;
        }

        return digits;
    }
};