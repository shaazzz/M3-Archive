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

const pii des = { -66,-66016 };

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

bool c = false;
void cheat(ll a, int k)
{
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
	mov(a);
}

bool xcheck()
{
	if (x == -66 && (y & 1) == 1 && y < 0)
		return true;
	if (x == -66016 && (y & 1) == 1 && y < 0)
		return true;
	if (y == -66 && (x & 1) == 1 && x < 0)
		return true;
	if (y == -66016 && (x & 1) == 1 && x < 0)
		return true;
	return false;
}

pii findes;
pii findi;
void Solve(ll cp, ll cnt, ll aa, int dd)
{
	c = false;
	x = 0; y = 0;
	di = { 0, 1 };
	for (ll i = 0; i < cnt; i++)
	{
		if (i == cp)
		{
			cheat(aa, dd);
			continue;
		}
		mov(rot(i + 1));
	}
	findes = { x,y };
	findi = di;
}

bool rcheck()
{
	return findes.first == des.first && findes.second == des.second;
}

int main()
{
	for(int cnt = 1;;cnt++)
	{
		Loop(cp, 0, cnt)
		{
			Loop(d, 0, 4)
			{
				Solve(cp, cnt, 1000000000LL, d);
				if (xcheck())
				{
					cout << "cnt: " << cnt << '\n';
					cout << "cp: " << cp << '\n';
					cout << "d: " << d << '\n';
					cout << findes.first << ' ' << findes.second << "\n";
					printf("FINAL ANS: %lli\n", (ll)cnt * cnt % delta);
					return 0;
				}
			}
		}
	}
}
