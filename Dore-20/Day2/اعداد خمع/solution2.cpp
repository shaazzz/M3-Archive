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

const int n = 1000000;
const int delta = 97987;

struct item
{
	ll x;
	ll sum;
}a[n];

int main()
{
	Loop(i, 2, n)
		a[i].x = i;
	for (int i = 2; i < n; i++)
	{
		a[i].sum = 1;
		ll d;
		for (d = 2; d * d < a[i].x; d++)
		{
			if (a[i].x % d == 0)
			{
				a[i].sum += d;
				a[i].sum += a[i].x / d;
			}
		}
		if (d * d == a[i].x)
			a[i].sum += d;
	}
	sort(a + 2, a + n, [](item a, item b)
		{
			return b.x * a.sum > a.x* b.sum || (b.x * a.sum == a.x * b.sum && a.x < b.x);
		});
	Loop(i, 2, 15)
	{
		cout << i-1 << ": " << a[i].x << "\tsum: " << a[i].sum << "\tratio: " << ' ' << (double)a[i].sum/a[i].x << '\n';
	}
	ll V = a[14].x % delta;
	V = (V * V * V + V * V) % delta;
	cout << "answer: " << V << '\n';
}
