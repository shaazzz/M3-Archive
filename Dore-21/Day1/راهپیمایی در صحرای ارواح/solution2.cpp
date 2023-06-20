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

bool been(int x, int y)
{
	if (abs(2 * x - 1) + abs(2 * y + 1) <= 63244)
		return true;
	return false;
}

int cnt = 31622 * (31622 + 1) * 2 - 1;
ll x = -31621;
ll y = 0;
int d = 3;

void rot90()
{
	d = (d + 1) % 4;
}
void rot180()
{
	d = (d + 2) % 4;
}
void step()
{
	switch (d)
	{
	case 0: y++; break;
	case 1: x++; break;
	case 2: y--; break;
	case 3: x--; break;
	}
}

int main()
{
	while (cnt < 2000000000)
	{
		step();
		if (been(x, y))
		{
			rot180();
			step();
			step();
		}
		rot90();
		cnt++;
	}
	cout << x << ' ' << y << '\n';
	cout << abs(x * y) << '\n';
	cout << abs(x * y)%delta << '\n';
}
