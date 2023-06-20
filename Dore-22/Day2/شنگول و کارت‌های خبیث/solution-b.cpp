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

int per[10] = { 1,2,3,4,5,6,7,8,9,10 };
int s[11] = { -1,1,2,2,3,3,3,3,4,4,4};

void add(int i)
{
begin:
	per[i]++;
	if (per[i] == 11)
	{
		per[i] = 1;
		add(i - 1);
	}
	for (int j = 0; j < i; j++)
		if (per[j] == per[i])
			goto begin;
}

ll ans = 0;
bool can[1 << 29] = {};
void create()
{
	ll x = 0;
	for (int i = 0; i < 10; i++)
	{
		x *= 1LL << s[per[i]];
		x += per[i];
	}
	ans += !can[x];
	can[x] = true;
}

int main()
{
	const int n = 3628800;
	for (int i = 0; i < n; i++)
	{
		create();
		add(9);
	}
	printf("can  : %lli\n", ans);
	printf("can't: %lli\n", (1LL << 29) - ans);
	ans = ((1LL << 29) - ans) % delta;
	ans = ans * ans % delta;
	printf("ans  : %lli\n", ans);
}
