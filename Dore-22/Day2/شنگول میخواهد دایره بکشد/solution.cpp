#define _CRT_SECURE_NO_WARNINGS
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
#define Kill(x) {cout << x << '\n'; return 0;}
using namespace std;

const int delta = 11287;

int log2(ll x)
{
	int ans = 0;
	while (x > 0)
	{
		ans++;
		x /= 2;
	}
	return ans;
}

int main()
{
	const ll x = delta * delta;
	printf("1: %lli\n", (1LL << (log2(x) - 1)) * (1LL << (log2(x) - 1)) * 3 % delta);

	ll ans = 0;
	ll y = x;
	while(y > 1)
	{
		ll k = 1LL << (log2(y) - 1);
		ll l = 1LL << (log2(y - k) - 1);
		ans += 3 * (l % delta) * (l % delta) % delta;
		y = k - 1;
	}
	printf("2: %lli\n", ans % delta);

	printf("3: %lli\n", (1LL << (log2(x) - 1)) * (1LL << (log2(x) - 1)) * 3 % delta);
}
