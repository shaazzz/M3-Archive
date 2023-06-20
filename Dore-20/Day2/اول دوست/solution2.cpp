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

const ll delta = 97987;

const int n = 1389000;
int dig;

bool isPrime(int x)
{
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
			return 0;
	}
	return 1;
}

int digSize(int x)
{
	int ans = 0;
	while (x > 0)
	{
		x /= 10;
		ans++;
	}
	return ans;
}

int pow(int a, int b)
{
	if (b == 0)
		return 1;
	return a * pow(a, b - 1);
}

int Count(int x, int size, int s)
{
	int h = (n / pow(10, s)) % pow(10, size);
	int l = n / pow(10, s + size);
	int r = n % pow(10, s);
	if (x < h)
	{
		return (l+1) * pow(10, s);
	}
	if (x == h)
	{
		return (l * pow(10, s) + r) + 1;
	}
	if (x > h)
	{
		return l * pow(10, s);
	}
	assert(false);
}

int main()
{
	ll ans = 0;
	dig = digSize(n);
	for (int i = 2; i <= n; i++)
	{
		if (isPrime(i))
		{
			int size = digSize(i);
			for (int j = 0; j + size <= dig; j++)
				ans += Count(i, size, j);
		}
	}
	cout << (ans % delta) << '\n';
}
