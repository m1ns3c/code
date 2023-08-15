// 20. 有效的括号
#include "../def.h"

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push(s[0]);

        for (int i=1; i<s.size(); i++) {
            if (!st.empty()) {
                switch (st.top()) {
                    case '(':
                        s[i] == ')' ? st.pop() : st.push(s[i]);
                    break;
                    case '{':
                        s[i] == '}' ? st.pop() : st.push(s[i]);
                    break;
                    case '[':
                        s[i] == ']' ? st.pop() : st.push(s[i]);
                    break;
                }
            } else {
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};