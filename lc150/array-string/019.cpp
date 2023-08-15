// 42. 接雨水
#include "../def.h"

// 1.贪心
// 双循环，分割最大值
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) {
            return 0;
        }

        vector<int> left(n, 0);

        int max = height[0], maxPos = 0;
        for (int i=1; i<n; i++) {
            if (height[i] > max) {
                max = height[i];
                maxPos = i;
            }
            left[i] = max - height[i];
        }

        max = height[n-1];
        for (int i=n-1; i>=maxPos; i--) {
            if (height[i] > max) {
                max = height[i];
            }
            left[i] = max - height[i];
        }

        int sum = 0;
        for (int i=0; i<n; i++) {
            sum += left[i];
        }

        return sum;
    }
};

// 2. DP


// 3. 双指针


// 4. 单调栈
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) {
            return 0;
        }

        stack<int> s;
        int ans = 0;
        for (int i=0; i<n; i++) {
            while (!s.empty() && height[s.top()] < height[i]) {
                int top = s.top();
                s.pop();

                if (s.empty()) {
                    break;
                }

                int left = s.top();
                int curWidth = i - left - 1;
                int curHeight = min(height[left], height[i]) - height[top];

                ans += curWidth * curHeight;
            }
            s.push(i);
        }
        return ans;
    }
};