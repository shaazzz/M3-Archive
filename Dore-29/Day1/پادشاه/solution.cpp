#include <bits/stdc++.h>
#define Loop(x,l,r) for (ll x = (l); x < (ll)(r); ++x)
#define LoopR(x,l,r) for (ll x = (r)-1; x >= (ll)(l); --x)
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll , ll > pll;
using namespace std;

const int mod = 1e9+7;

const int N = 1e6+10;

ll fct[N],fcti[N];
ll pw(ll x,ll y){ll a=1;while(y){if(y&1)a=a*x%mod;x=x*x%mod;y/=2;}return a;}
void init(){fct[0]=fcti[0]=1;Loop(i,1,N){fct[i]=fct[i-1]*i%mod;fcti[i]=pw(fct[i],mod-2);}}
ll C(int n,int r){return r<0||n<r?0:fct[n]*fcti[r]%mod*fcti[n-r]%mod;}

ll g(int n, int k)
{
	const int lg = 20;
	vector<ll> dp(n+1, 1);
	dp[0]=0;
	ll ans = n;
	Loop (i,2,lg) {
		for (int x = 1; x <= n; ++x) {
			dp[x] = 0;
			for (int y = 2*x; y <= n; y += x)
				dp[x] += dp[y];
			dp[x] %= mod;
			ans += C(k-1, i-1) * dp[x];
			ans %= mod;
		}
	}
	return ans;
}

const int delta = 229939;

int main()
{
	vector<tuple<int,int,int>> in = {
		{50, 3, 3},
		{1e5, 100, 3},
		{1e5, 1e6, 3},
	};
	init();
	for (auto [n, k, p] : in) {
		ll x = g(n, k);
		ll ans = 1;
		while (p--)
			ans = ans*x % delta;
		cout << ans << '\n';
	}
}
