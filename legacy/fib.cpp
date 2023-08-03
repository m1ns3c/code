#include <stdio.h>
#include <vector>

using namespace std;

// fib 1
// recurive
int fib1(int n) {
    if (n < 2) {
        return n;
    }

    return fib1(n-2) + fib1(n-1);
}

vector<int> memo = {1, 1};

// fib 2
// memorization
int fib2(int n) {
    if (!memo[n]) {
        memo[n] = fib2(n-2) + fib2(n-1);
    }

    return memo[n];
}

// fib 3
// sentinel
int fib3(int n) {
    if (n == 0) {
        return 1;
    }
    
    int last = 1;
    int next = 1;

    for (int i=1; i<n; i++) {
		int t = last + next;
		last = next;
		next = t;
    }

    return next;
}
