// 55. 跳跃游戏
#include "../def.h"

// 贪心
class Solution1 {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int rightmost = 0;

        for (int i=0; i<n; i++) {
            if (i <= rightmost) {
                rightmost = max(rightmost, i+nums[i]);
                if (rightmost >= n-1) {
                    return true;
                }
            }
        }

        return false;
    }
};

// DP
class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 0);
        dp[0] = nums[0];

        if (n == 1) {
            return true;
        }
        if (nums[0] == 0) {
            return false;
        }

        for (int i=1; i<n; i++) {
            dp[i] = max(dp[i-1], i+nums[i]);
            if (dp[i] >= n-1) {
                return true;
            }
            if (dp[i] == i) {
                return false;
            }
        }

        return false;
    }
};

// BFS
class Solution3 {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return true;
        }

        queue<int> q;
        map<int, int> visited;
        int right = 0;

        q.push(0);

        while (!q.empty()) {
            int index = q.front();
            q.pop();

            if (index + nums[index] >= n - 1) {
                return true;
            }

            for (int i=right+1; i<index+nums[index]+1; i++) {
                if (!visited[i]) {
                    q.push(i);
                    visited[i] = 1;
                }
            }
            right = index + nums[index];
        }

        return false;
    }
};