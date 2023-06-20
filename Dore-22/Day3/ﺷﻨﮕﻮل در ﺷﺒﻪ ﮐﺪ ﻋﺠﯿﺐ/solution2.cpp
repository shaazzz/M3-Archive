#include <bits/stdc++.h>
#define Loop(x,l,r) for (ll x = (l); x < (ll)(r); ++x)
#define LoopR(x,l,r) for (ll x = (r)-1; x >= (ll)(l); --x)
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll , ll > pll;
using namespace std;

const int mod = 229939;
const int sz = 8;
ll a[sz] = {972,  -1, 273, -1, 932, 911,  -1, 233};
ll b[sz] = { -1, 942, 135, -1, 371,  -1, 311,  -1};
ll dp[sz+1][1000];
int cntn1[sz+1];

int main()
{
	dp[0][777] = 1;
	Loop (i,0,sz) {
		Loop (c,0,1000) {
			Loop (x, a[i]==-1?100:a[i], a[i]==-1?1000:a[i]+1)
			Loop (y, b[i]==-1?100:b[i], b[i]==-1?1000:b[i]+1) {
				int c2 = (c * x + i + 1) % y;
				dp[i+1][c2] += dp[i][c];
				dp[i+1][c2] %= mod;
			}
		}
	}
	LoopR (i,0,sz)
		cntn1[i] = cntn1[i+1] + (a[i] == -1) + (b[i] == -1);
	for (int k : {2, 4, 8}) {
		ll ans = dp[k][777];
		Loop (_,0,cntn1[k]) {
			ans *= 900;
			ans %= mod;
		}
		cout << ans << '\n';
	}
}
