#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES": "NO")
#define all(x) x.begin(),x.end()
#define ll long long
#define pii pair<int,int>
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

const int delta = 10007;

ll pow(ll a, ll b, ll mod)
{
	return b == 0 ? 1 : a * pow(a, b - 1, mod) % mod;
}

int main()
{
	ll x = pow(1389, 1431, 1000000);
	ll ans = 1;
	Loop (_,0,6) {
		ans *= x % 10;
		ans %= delta;
		x /= 10;
	}
	cout << ans << '\n';
}
