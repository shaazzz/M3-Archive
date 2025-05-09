#include <iostream>
#include <numeric>
using namespace std;

const int DELTA = 10427;
const int N = 1e3 + 5;
int fact[N], C[N][N];

namespace subtask1 {
    const int W = 100 + 5, N = 10 + 5;
    int dp[W][N];

    void solve(int w, int n) {
        for (int i = 0; i <= w; i++) {
            dp[i][0] = 1;
            dp[i][1] = C[i + 1][2];
            dp[i][2] = 3LL * C[i + 1][4] % DELTA;
            for (int j = 3; j <= n && 2 * j <= i + 1; j++) {
                dp[i][j] = dp[i - 1][j];
                for (int k = i - 1; k; k--)
                    (dp[i][j] += dp[k - 1][j - 1]) %= DELTA;
                for (int k = i - 3; k; k--)
                    (dp[i][j] += 2LL * dp[k - 1][j - 2] * C[i - k - 1][2] % DELTA) %= DELTA;
            }
        }
        cout << 1LL * fact[n] * dp[w][n] % DELTA << endl;
    }
}

namespace subtask2 {
    const int N = 50 + 5;
    int dp[N][3];

    void solve(int w, int n) {
        dp[0][0] = dp[1][0] = dp[2][0] = 1, dp[2][1] = 2;
        for (int i = 3; i <= n; i++)
            for (int y = 0; y < 3; y++) {
                (dp[i][0] += dp[i - 1][y]) %= DELTA;
                (dp[i][1] += dp[i - 2][y]) %= DELTA;
                (dp[i][2] += 7LL * dp[i - 3][y] % DELTA) %= DELTA;
                if (y < 2) {
                    (dp[i][1] += dp[i - 1][y]) %= DELTA;
                    (dp[i][2] += dp[i - 2][y]) %= DELTA;
                }
            }

        int ans = 0;
        for (int i = 0; i < 3; i++)
            (ans += dp[n][i]) %= DELTA;
        cout << 1LL * fact[n] * ans % DELTA * C[w + 1][n << 1] % DELTA << endl;
    }
}

namespace subtask3 {
    const int N = 100 + 5;
    int dp[N][4];

    void solve(int w, int n) {
        dp[0][0] = dp[1][0] = dp[2][0] = 1, dp[2][1] = 2;
        dp[3][0] = 3, dp[3][1] = 4, dp[3][2] = 8;
        dp[4][0] = 15, dp[4][1] = 18, dp[4][2] = 24, dp[4][3] = 48;
        for (int i = 5; i <= n; i++) {
            dp[i][2] = 4LL * dp[i - 3][0] % DELTA;
            dp[i][3] = 4LL * dp[i - 4][0] % DELTA;
            for (int y = 0; y < 4; y++) {
                (dp[i][0] += dp[i - 1][y]) %= DELTA;
                (dp[i][1] += dp[i - 2][y]) %= DELTA;
                (dp[i][2] += 3LL * dp[i - 3][y] % DELTA) %= DELTA;
                (dp[i][3] += 37LL * dp[i - 4][y] % DELTA) %= DELTA;
                if (y < 3) {
                    (dp[i][1] += dp[i - 1][y]) %= DELTA;
                    (dp[i][2] += dp[i - 2][y]) %= DELTA;
                    (dp[i][3] += 3LL * dp[i - 3][y] % DELTA) %= DELTA;
                }
                if (y < 2) {
                    (dp[i][2] += 4LL * dp[i - 2][y] % DELTA) %= DELTA;
                    (dp[i][2] += 2LL * dp[i - 3][y] % DELTA) %= DELTA;
                    (dp[i][3] += 8LL * dp[i - 3][y] % DELTA) %= DELTA;
                    (dp[i][3] += 2LL * dp[i - 4][y] % DELTA) %= DELTA;
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < 4; i++)
            (ans += dp[n][i]) %= DELTA;
        cout << 1LL * fact[n] * ans % DELTA * C[w + 1][n << 1] % DELTA << endl;
    }
}

void prepare() {
    fact[0] = C[0][0] = 1;
    for (int i = 1; i < N; i++) {
        C[i][0] = 1;
        fact[i] = 1LL * fact[i - 1] * i % DELTA;
        for (int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % DELTA;
    }
}

int main() {
    prepare();
    subtask1::solve(100, 10);
    subtask2::solve(400, 50);
    subtask3::solve(1000, 100);
}