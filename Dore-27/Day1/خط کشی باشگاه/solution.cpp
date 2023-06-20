#include <bits/stdc++.h>
#define Loop(x,l,r) for (ll x = (l); x < (ll)(r); ++x)
#define LoopR(x,l,r) for (ll x = (r)-1; x >= (ll)(l); --x)
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll , ll > pll;
using namespace std;

#define int ll

const int mod = 10067;
const int N = 10020;

int C[N][N];

void init()
{
	C[0][0] = 1;
	Loop (i,1,N) {
		C[i][0] = C[i][i] = 1;
		Loop (j,1,i)
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
	}
}

int Do2(int u, int lr, bool dard)
{
	int ans = 0;
	Loop (k,0,dard? lr+1: 1) {
		Loop (i,0,u) Loop (j,i+1,u+1) {
			int a, b;
			int x, y;

			a = i;
			b = (lr-k)/2;
			x = b? C[a+b-1][a]: a? 0: 1;

			a = u-j;
			b = (lr-k+1)/2;
			y = b? C[a+b-1][a]: a? 0: 1;

			ans = (ans + x*y) % mod;
		}
	}
	return ans;
}

void calc_dp(ll *dp, int n, int l, int r)
{
	Loop (j,l,r)
		dp[j] = Do2(n, j, 0);
}

void Do3()
{
	int constexpr n = 3000;
	static ll dp[2*n];
	//vector<thread> ts;
	//Loop (i,0,8)
	//	ts.push_back(thread(calc_dp, dp, n, 2*n*i/8, 2*n*(i+1)/8));
	//Loop (i,0,8)
	//	ts[i].join();
	Loop (j,0,2*n)
		dp[j] = Do2(n, j, 0);
	ll ans = 0;
	Loop (i,0,2*n) Loop (j,i+1,2*n+1)
		ans = (ans + dp[i] * dp[2*n-j]) % mod;
	ans = ans*2 % mod;
	cout << ans << '\n';
}

signed main()
{
	init();
	cout << C[20][10] << '\n';
	cout << Do2(200, 400, 1) << '\n';
	Do3();
}
