// 53. 最大子数组和
#include "../def.h"

// 包含尽可能多的正数
// 与最值无关
// 正数开头，正数结尾 -> 正数的开始 和 结束位置范围内
// 全部都为负数 -> 最大值
// 如何分类正 负数

// O(n) 遍历 正数开始和结束位置
// 升级：标记正数位置 5,10,20
// 5 | 5~10 | 5~20
// 10 | 10~20
// 20

// 区间和 正|负
// 区间和 负 肯定不是最大和

// 找到第一个正数
// 开始累加到下一个正数
// 和是正负

// 错误
class Solution {
public:
    int max;
    void dac(vector<int>& nums, vector<int>& pos, int left, int right) {
        if (left == right) {
            if (nums[pos[left]] > max) {
                max = nums[pos[left]];
            }
            return;
        } else if (left > right) {
            return;
        }

        int mid = (left + right) >> 1;

        dac(nums, pos, left, mid);
        dac(nums, pos, mid+1, right);
    }

    int maxSubArray(vector<int>& nums) {
        vector<int> positive;

        int max;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] > 0) {
                positive.push_back(i);
            }

            if (nums[i] > max) {
                max = nums[i];
            }
        }

        if (positive.size() <= 1) {
            return max;
        } else {
            // 区间
            dac(nums, positive, 0, positive.size()-1);
            return max;
        }
    }
};

// 1.DP
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, ans = nums[0];
        for (int i=0; i<nums.size(); i++) {
            pre = max(pre+nums[i], nums[i]);
            ans = max(ans, pre);
        }
        return ans;
    }
};

// 分解 DP
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();


        vector<int> dp(n);
        dp[0] = nums[0];
        int max = dp[0];
        int i = 1;
        while (i < n) {
            dp[i] = fmax(dp[i-1] + nums[i], nums[i]);
            if (dp[i] > max) {
                max = dp[i];
            }
            i++;
        }
        return max;
    }
};

// 2.分治
