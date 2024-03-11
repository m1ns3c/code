// 
#include "../def.h"

// 优先队列（底层堆实现）
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        auto cmp = [&nums1, &nums2](const pair<int, int> &a, const pair<int, int> &b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        vector<vector<int>> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        int m = nums1.size();
        int n = nums2.size();
        for (int i = 0; i < min(k, m); i++) {
            pq.emplace(i, 0);
        }

        while (k-- > 0 && !pq.empty()) {
            auto [x, y] = pq.top();
            pq.pop();
            res.emplace_back(initializer_list<int>{nums1[x], nums2[y]});
            if (y + 1 < n) {
                pq.emplace(x, y + 1);
            }
        }
        return res;
    }
};

// 超时
class Solution {
public:
    void heapify(vector<vector<int>> &res, int n, int i) {
        int smallest = i;
        int lc = 2 * i + 1;
        int rc = 2 * i + 2;
        if (lc < n && (res[lc][0] + res[lc][1]) < (res[smallest][0] + res[smallest][1])) {
            smallest = lc;
        }
        if (rc < n && (res[rc][0] + res[rc][1]) < (res[smallest][0] + res[smallest][1])) {
            smallest = rc;
        }
        if (smallest != i) {
            swap(res[smallest], res[i]);
            heapify(res, n, smallest);
        }
    }

    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<vector<int>> temp;
        vector<vector<int>> ans;
        for (int i = 0; i < nums1.size() && i < k; i++) {
            for (int j = 0; j < nums2.size() && j < k; j++) {
                temp.push_back({nums1[i], nums2[j]});
            }
        }
        int n = temp.size();
        if (n <= k) {
            return temp;
        }
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(temp, n, i);
        }
        for (int i = n - 1; i >= n - k; i--) {
            ans.push_back(temp[0]);
            swap(temp[i], temp[0]);
            heapify(temp, i, 0);
        }
        return ans;
    }
};