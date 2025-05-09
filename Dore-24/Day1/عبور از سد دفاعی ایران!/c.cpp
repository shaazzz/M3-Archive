#include <bits/stdc++.h>
#define ff first
#define ss second
#define dbg(x) cout << #x << ": " << x << '\n';
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int mod = 26003;

ll po(ll b, ll p){
	return (p == 0 ? 1 : po(b*b%mod, p/2) * (p & 1 > 0 ? b : 1) % mod);
}

const int n = 20000;
const int m = 10000;

// jabab = tedad block haie 0/1 ke 1 daran

// dp[i][0] -> javab baraie hame halat i ta, ke akharesh ie block az 2 ha
// dp[i][1] -> javab baraie hame halat i ta, ke akharesh ie block kamel 0
// dp[i][2] -> javab baraie hame halat i ta, ke akharesh ie block 0/1 ke 1 dare
// cnt[i][0] -> tedad halat i ta, ke akharesh ie block az 2 ha
// cnt[i][1] -> tedad halat i ta, ke akharesh ie block kamel 0
// cnt[i][2] -> tedad halat i ta, ke akharesh ie block 0/1 ke 1 dare

int dp[n][3], cnt[n][3];

signed main(){
    int ans = 0;
    for(int i = 1; i <= m; i++){
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] = 0;
        cnt[0][0] = 1;
        cnt[0][1] = 0;
        cnt[0][2] = 0;
        for(int j = 1; j <= n; j++){
            (dp[j][0] = (dp[j-1][0] + dp[j-1][1] + dp[j-1][2]) * (m-i) % mod + (j-1 > 0 ? cnt[j-1][2] : 0) * (m-i) % mod) %= mod;
            (dp[j][1] = (dp[j-1][0] + dp[j-1][1]) * (i-1) % mod) %= mod;
            (dp[j][2] = (dp[j-1][0] + dp[j-1][1] + dp[j-1][2]) + dp[j-1][2] * (i-1) % mod) %= mod;
            (cnt[j][0] = (cnt[j-1][0] + cnt[j-1][1] + cnt[j-1][2]) * (m-i) % mod) %= mod;
            (cnt[j][1] = (cnt[j-1][0] + cnt[j-1][1]) * (i-1) % mod) %= mod;
            (cnt[j][2] = (cnt[j-1][0] + cnt[j-1][1] + cnt[j-1][2]) + cnt[j-1][2] * (i-1) % mod) %= mod;
            // cout << dp[j][0] << ' ' << dp[j][1] << ' ' << dp[j][2] << " | " << cnt[j][0] << ' ' << cnt[j][1] << ' ' << cnt[j][2];
        }
        // cout << '\n';
        ans += (dp[n][0] + dp[n][1] + dp[n][2] + cnt[n][2]);
        ans %= mod;
    }

    cout << ans << '\n';
}
