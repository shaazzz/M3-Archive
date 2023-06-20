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

bool tree[1000000000] = {};

int lef(int x) { return 2 * x + 1; }
int rig(int x) { return 2 * x + 2; }

int p = 1;
void Do(bool y)
{
	if (y == 0)
	{
		if (tree[lef(p)])
			p = lef(p);
		else
		{
			tree[lef(p)] = true;
			p = 1;
		}
	}
	else
	{
		if (tree[rig(p)])
			p = rig(p);
		else
		{
			tree[rig(p)] = true;
			p = 1;
		}
	}

}

int main()
{
	tree[1] = true;
	for (int i = 1389; i <= 2010; i++)
	{
		for (int j = 10; j >= 0; j--)
		{
			Do(Bit(i, j));
		}
	}
	ll N = 0, L = 0;
	for (int i = 1; i < 1000000000; i++)
	{
		if (tree[i]) {
			N++;
			if (!tree[lef(i)] && !tree[rig(i)])
				L++;
		}
	}
	N %= delta;
	L %= delta;
	ll temp = (N * L) % delta;
	cout << (temp * temp) % delta << '\n';
}
