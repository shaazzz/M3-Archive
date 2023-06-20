#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <unordered_map>
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

const int delta = 11287;

pii di = { 0,1 };
ll x = 0, y = 0;

ll rot(ll p)
{
	int k = 0;
	while (!(p & 1))
	{
		k++;
		p >>= 1;
	}
	k %= 4;
	while (k--)
	{
		if (di.second)
		{
			di.first = di.second;
			di.second = 0;
		}
		else
		{
			di.second = -di.first;
			di.first = 0;
		}
	}
	return p;
}

void mov(ll p)
{
	x += p * di.first;
	y += p * di.second;
}

int main()
{
	for (int i = 0;i < delta * delta; i++)
	{
		mov(rot(i + 1));
	}
	printf("x  : %lli\n", x);
	printf("y  : %lli\n", y);
	x %= delta; y %= delta;
	x += delta; y += delta;
	x %= delta; y %= delta;
	printf("ans: %lli\n", (x * y + x + y) % delta);
}
