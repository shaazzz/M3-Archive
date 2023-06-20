#include <bits/stdc++.h>
#define Loop(x,l,r) for (ll x = (l); x < (ll)(r); ++x)
#define LoopR(x,l,r) for (ll x = (r)-1; x >= (ll)(l); --x)
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll , ll > pll;
using namespace std;

const int mod = 229939;

ll pw(ll x, ll y) {
	ll ans = 1;
	while (y) {
		if (y&1)
			ans = ans*x % mod;
		x = x*x % mod;
		y /= 2;
	}
	return ans;
}

const int N = 1e5+10;
ll fct[N], ifct[N];

void init()
{
	fct[0] = ifct[0] = 1;
	Loop (i,1,N) {
		fct[i] = fct[i-1] * i % mod;
		ifct[i] = pw(fct[i], mod-2);
	}
}
ll C(int n, int r) { return fct[n] * ifct[r] % mod * ifct[n-r] % mod; };

ll f(int n, int k)
{
	vector<vector<ll>> dp(n+1, vector<ll>(n+1));
	Loop (i,0,n+1) Loop (j,0,n+1) {
		if (i+j > n)
			break;
		if (!j) {
			dp[i][j] = 0;
			continue;
		}
		if (!i) {
			dp[i][j] = (j + k - 1) / k;
			continue;
		}
		dp[i][j] += dp[i-1][j];
		Loop (x,1,min<int>(j,k-1)+1)
			dp[i][j] += dp[i-1][j-x] + C(i+j-1-x, i-1);
		if (j >= k)
			dp[i][j] += dp[i][j-k] + C(i+j-k, i);
		dp[i][j] %= mod;
	}
	ll ans = 0;
	Loop (i,0,n) {
		ans += dp[i][n-i] * fct[i] % mod * fct[n-i];
		ans %= mod;
	}
	return ans;
}

int main()
{
	init();
	cout << f(10, 4) << '\n';
	cout << f(100, 43) << '\n';
	cout << f(10000, 400) << '\n';
}
