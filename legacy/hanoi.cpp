#include <vector>

using namespace std;

class Solution {
public:
    void move(vector<int>& start, vector<int>& end, vector<int>& temp, int n) {
        if (n == 1) {
            end.push_back(start.back());
            start.pop_back();
        } else {
            move(start, temp, end, n-1); // top n-1 A->B
            move(start, end, temp, 1);  // bottom 1 A->C
            move(temp, end, start, n-1); // top n-1 B->C
        }
    }

    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        move(A, C, B, A.size());
    }
};
