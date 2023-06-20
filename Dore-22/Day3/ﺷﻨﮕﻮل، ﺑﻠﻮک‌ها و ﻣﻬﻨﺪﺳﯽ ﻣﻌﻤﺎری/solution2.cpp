#include <bits/stdc++.h>
#define Loop(x,l,r) for (ll x = (l); x < (ll)(r); ++x)
#define LoopR(x,l,r) for (ll x = (r)-1; x >= (ll)(l); --x)
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll , ll > pll;
using namespace std;

const int mod = 229939;

set<ll> P(int n)
{
	set<ll> ans;
	Loop (i,1,1<<(n/2)) {
		int sz = __lg(i)+1;
		ll x = i;
		for (int j = 1; (j+1)*sz <= n; ++j) {
			x ^= i << j*sz;
			ans.insert(x);
		}
	}
	return ans;
}

int main()
{
	/* sub1 */ {
		ll ans = 1;
		for (ll x : P(8))
			ans = ans * x % mod;
		cout << ans << '\n';
	}
	cout << P(24).size() % mod << '\n'; // a^p = a mod p
	cout << P(48).size() % mod << '\n';
}
