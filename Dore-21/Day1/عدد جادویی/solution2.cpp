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

const ll n = 38244492;
int X[n+1];

int main()
{
	time_t st = time(0);
	for (ll i = 1; i <= n * 210; i++)
	{
		ll a = i;
		if (i % 2)
			a *= 2;
		if (i % 3)
			a *= 3;
		if (i % 5)
			a *= 5;
		if (i % 7)
			a *= 7;
		for (ll j = a; j <= n*210; j+=a)
		{
			X[j / 210]++;
		}
	}
	for (ll i = 1; i <= n; i++)
	{
		if (X[i] >= 2011)
		{
			cout << i * 210 << '\t' << X[i] << '\n';
			cout << "The answer: " << i * 210 % delta << '\n';
			break;
		}
	}
	cout << "time: " << difftime(time(0), st) << '\n';
}
