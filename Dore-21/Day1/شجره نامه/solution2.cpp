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

const ll delta = 29123;

bool isPrime(ll p)
{
	if (p < 2)
		return false;
	for (int i = 2; i * i <= p; i++)
		if (p % i == 0)
			return false;
	return true;
}

int log2(ll x)
{
	int ans = 0;
	while (x > 0)
	{
		ans++;
		x >>= 1;
	}
	return ans;
}

ll lca(ll a, ll b)
{
	int p1 = log2(a) - 1;
	int p2 = log2(b) - 1;
	int ans = 0;
	while (p1 >= 0 && p2 >= 0)
	{
		if (Bit(a, p1) != Bit(b, p2))
			break;
		ans <<= 1;
		ans |= Bit(a, p1);
		p1--;
		p2--;
	}
	return ans;
}

int D(ll a, ll b)
{
	ll anc = lca(a, b);
	return log2(a) + log2(b) - 2 * log2(anc);
}

int main()
{
	ll ans = 1;
	for (ll a = 1; a <= delta; a++)
	{
		if (!isPrime(a))
			continue;
		//cout << "..." << a << '\n';
		for (ll b = a + 1; b <= delta; b++)
		{
			if (isPrime(b) && isPrime(a + b + 1))
			{
				//printf("a: %i\tb: %i\tlca: %i\tD: %i\n", a, b, lca(a, b), D(a, b));
				ans *= D(a, b);
				ans %= delta;
			}
		}
	}
	cout << ans << '\n';
}
