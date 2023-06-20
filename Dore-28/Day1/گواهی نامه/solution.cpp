#include <bits/stdc++.h>
#define Loop(x,l,r) for (ll x = (l); x < (ll)(r); ++x)
#define LoopR(x,l,r) for (ll x = (r)-1; x >= (ll)(l); --x)
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll , ll > pll;
using namespace std;

const int mod = 229939;
const int n = 50;

ll pw(ll x, ll y)
{
	y %= mod-1;
	y = y < 0? y + mod-1: y;
	ll a = 1;
	while (y) {
		if (y&1)
			a = a*x % mod;
		x = x*x % mod;
		y /= 2;
	}
	return a;
}

void Do1()
{
	ll ans = 0;
	Loop (i,0,n) Loop (j,0,n) {
		ans += pw(2, n*n - i - j - 1);
		ans %= mod;
	}
	ans = ans * 4 % mod;
	cout << ans << '\n';
}

void Do2()
{
	ll ans = 0;
	Loop (i,0,n) Loop (j,i+1,n) {
		Loop (k,0,n-1) {
			ans += pw(2, n*n - (j - i + 1 + k + k) - 2) * 3;
			ans %= mod;
		}
		ans += pw(2, n*n - (j - i - 1 + n + n));
		ans %= mod;
	}
	ans = ans * 4 % mod;
	cout << ans << '\n';
}

ll dp[n][n];

void Do3()
{
	dp[0][0] = pw(2, -4);
	Loop (i,0,n) Loop (j,0,n) {
		if (!i && !j)
			continue;
		dp[i][j] = pw(2, -(4 + 2*i + 2*j));
		Loop (x,0,i) Loop (y,0,j)
			dp[i][j] -= dp[x][y] * pw(2, -(4 + 2*i + 2*j - x - y - 3)) % mod;
		Loop (x,0,i)
			dp[i][j] -= dp[x][j] * pw(2, -(2 + 2*i + j - 2*x - 2)) % mod;
		Loop (y,0,j)
			dp[i][j] -= dp[i][y] * pw(2, -(2 + i + 2*j - 2*y - 2)) % mod;
		dp[i][j] %= mod;
		dp[i][j] += mod;
		dp[i][j] %= mod;
	}
	ll ans = 0;
	Loop (i,0,n) Loop (j,0,n) Loop (x,0,n-i-1) Loop (y,0,n-j-1)
		ans = (ans + pw(2, n*n - i - j) * dp[x][y]) % mod;
	ans *= 4;
	ans %= mod;
	cout << ans << '\n';
}

void naive()
{
	int ans = 0;
	Loop (i,0,n) Loop (j,0,n) {
	cerr << i << ' ' << j << '\n';
	Loop (msk,0,1<<n*n) {
	#define idx(i, j) (((msk) >> ((i)*n + (j)))&1)
		Loop (x,i+1,n) Loop (y,j+1,n) {
			bool ok = 1;
			Loop (dard,0,x+1)
				ok &= idx(dard, j);
			Loop (dard,0,y+1)
				ok &= idx(i, dard);
			Loop (dard,i,x+1)
				ok &= idx(dard, y);
			Loop (dard,j,y+1)
				ok &= idx(x, dard);
			if (ok) {
				++ans;
				goto dard;
			}
		}
	#undef idx
	dard:
		;
	}
	}
	cout << ans*4 << '\n';
}

signed main()
{
	Do1();
	Do2();
	Do3();
	//naive();
}
