// 13. 罗马数字转整数
#include "../def.h"

class Solution {
public:
    int romanToInt(string s) {
        stack<char> stk;

        int num = 0;

        for (int i=0; i< s.length(); i++) {
            switch (s[i]) {
                case 'I':
                    stk.push(s[i]);
                    break;
                case 'V':
                    if (!stk.empty() && stk.top() == 'I') {
                        stk.pop();
                        num += 4;
                        break;
                    }
                    num += 5;
                    break;
                case 'X':
                    if (!stk.empty() && stk.top() == 'I') {
                        stk.pop();
                        num += 9;
                        break;
                    }
                    stk.push(s[i]);
                    break;
                case 'L':
                    if (!stk.empty() && stk.top() == 'X') {
                        stk.pop();
                        num += 40;
                        break;
                    }
                    num += 50;
                    break;
                case 'C':
                    if (!stk.empty() && stk.top() == 'X') {
                        stk.pop();
                        num += 90;
                        break;
                    }
                    stk.push(s[i]);
                    break;
                case 'D':
                    if (!stk.empty() && stk.top() == 'C') {
                        stk.pop();
                        num += 400;
                        break;
                    }
                    num += 500;
                    break;
                case 'M':
                    if (!stk.empty() && stk.top() == 'C') {
                        stk.pop();
                        num += 900;
                        break;
                    }
                    num += 1000;
                    break;
            }
        }

        while (!stk.empty()) {
            switch (stk.top()) {
                case 'I':
                    num += 1;
                    break;
                case 'X':
                    num += 10;
                    break;
                case 'C':
                    num += 100;
                    break;
            }
            stk.pop();
        }

        return num;
    }
};