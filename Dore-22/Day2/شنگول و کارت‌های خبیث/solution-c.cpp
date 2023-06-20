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

int per[16] = { 16,8,4,9,10,1,2,3,5,6,7,11,12,13,14,15 };
int s[17] = { -1,1,2,2,3,3,3,3,4,4,4,4,4,4,4,4,5 };

void add(int i)
{
begin:
	per[i]++;
	if (per[i] == 17)
	{
		per[i] = 1;
		add(i - 1);
	}
	for (int j = 0; j < i; j++)
		if (per[j] == per[i])
			goto begin;
}

unordered_map<ll, int> cnt;

ll ans = 1LL << 61;
void create()
{
	ll x = 0;
	for (int i = 0; i < 16; i++)
	{
		x *= 1LL << s[per[i]];
		x += per[i];
	}
	cnt[x]++;
	ans = min(ans, x);
}

int main()
{
	const int n = 39916800;
	for (int i = 0; i < n; i++)
	{
		if (i % 10000000 == 0)
			cout << i << '\n';
		create();
		add(15);
	}
	printf("min: %lli\n", ans);
	ll x = cnt[ans] * 2;
	printf("cnt: %lli\n", x);
	ans %= delta;
	printf("ans: %lli\n", ans * x % delta);
}
