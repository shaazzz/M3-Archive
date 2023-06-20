#include <bits/stdc++.h>
#define Loop(x,l,r) for (ll x = (l); x < (ll)(r); ++x)
#define LoopR(x,l,r) for (ll x = (r)-1; x >= (ll)(l); --x)
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll , ll > pll;
using namespace std;

const int mod = 229939;
const int N = 64;

ll dp[N][N][N];

ll f(int n)
{
	ll ans = 0;
	Loop (i,0,n) Loop (l,0,n-i) Loop (r,0,i+1) {
		if (l == 0 || (r == 0 && i)) {
			dp[i][l][r] = 1;
		} else if (r == 0) {
			dp[i][l][r] = dp[i][l-1][r]+1;
		} else {
			ll x = dp[i][l-1][r-1]+1;
			ll y = r == i? dp[i][l-1][r]+1: dp[i][l-1][r-1]+1;
			dp[i][l][r] = x*y % mod;
		}
		int cnt = n-1-r-(r!=i)-l-(l!=n-1-i);
		ll p2 = (1ull << cnt) % mod;
		ans += dp[i][l][r] * p2 % mod * ((1ull << i) % mod);
		ans %= mod;
	}
	return ans;
}

int main()
{
	cout << f(4)*f(4)*f(4)%mod << '\n';
	cout << f(16) << '\n';
	cout << f(64) << '\n';
}
