#include <iostream>
using namespace std;

const int DELTA = 10427;

namespace subtask1 {
    void solve(int n) {
        int answer = 1;
        for (int i = 1; i < n; i++)
            answer = ((1 << i) + (answer << 1 | 1)) % DELTA;
        cout << answer << endl;
    }
}

namespace subtask2 {
    const int N = 60 + 5;
    int dp[N];

    int calc(int i, long long &k) {
        if (k >= (1LL << i) - 1) {
            k -= (1LL << i) - 1;
            return dp[i];
        }
        if (!i || !k)
            return 0;

        int ans = (1LL << --i) % DELTA;
        (ans += calc(i, --k)) %= DELTA;
        if (k)
            (ans += 1 + calc(i, k)) %= DELTA;
        return ans;
    }

    void solve(int n, long long k) {
        dp[0] = 0, dp[1] = 1;
        for (int i = 1; i < n; i++)
            dp[i + 1] = ((1LL << i) + (dp[i] << 1 | 1)) % DELTA;
        cout << calc(n, --k) << endl;
    }
}

int main() {
    subtask1::solve(20);
    subtask2::solve(60, 12345678987654321LL);
}