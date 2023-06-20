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

const int delta = 97987;
pii a = { 1024,2010 }, b = { -1381,138 }, c = { 1,2010 };
//pii a = { 0,0 }, b = { 1,0 }, c = { 0,2 };

pii getNew(pii x, pii y)
{
	pii ans = x;
	if (x.first < y.first)
		ans.first++;
	if (x.first > y.first)
		ans.first--;
	if (x.second < y.second)
		ans.second++;
	if (x.second > y.second)
		ans.second--;
	if (ans == y)
		return x;
	return ans;
}

int main()
{
	int i = 0;
	for (i = 0;; i++)
	{
		printf("%i: (%i, %i) (%i, %i) (%i, %i)\n", i, a.first, a.second, b.first, b.second, c.first, c.second);
		pii h1, h2, h3;
		h1 = getNew(a, b);
		h2 = getNew(b, c);
		h3 = getNew(c, a);
		if (a == h1 && b == h2 && c == h3)
			break;
		a = h1; b = h2; c = h3;
	}
	ll x = i;
	x = x * x * x % delta;
	x = x * x % delta;
	cout << "answer: " << x << '\n';
}
