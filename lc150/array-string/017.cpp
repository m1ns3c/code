// 134. 加油站

#include "../def.h"

// 暴力破解
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for (int i=0; i<n; i++) {
            if (gas[i] < cost[i]) {
                continue;
            }

            int stocks = 0;
            int start = i;
            for (int j=i; j<i+n; j++) {
                int p = j%n;
                stocks += gas[p];
                stocks -= cost[p];
                if (stocks < 0) {
                    break;
                }
            }
            if (stocks >= 0) {
                return i;
            }
        }
        return -1;       
    }
};

// 贪心
// 到达能到达的最远的加油站

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int start = 0, i = 0;
        int stocks = 0;

        while(start <= n) {
            stocks += gas[i%n] - cost[i%n];
            if (stocks < 0) {
                stocks = 0;
                i++;
                start = i;
            } else {
                i++;
            }
			
			if (i - start >= n) {
				return start;
			}
        }

        return -1;
    }
};