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

const int delta = 28813;
const int n = 81;

int my_pow(ll a, ll b)
{
	return b == 0 ? 1 : a * my_pow(a, b - 1) % delta;
}

int p;
int cnt;
int rem;
bool a[n];
void go()
{
	const int nxt = 23;
	cnt += !a[p++];
	if (cnt == nxt)
	{
		cnt = 0;
		a[p - 1] = 1;
		rem--;
	}
	p %= n;
}

int winner(int s)
{
	memset(a, 0, n);
	p = s - 1;
	cnt = 0;
	rem = n;
	while (rem > 1)
		go();
	Loop(i, 0, n)
		if (!a[i])
			return i + 1;
	return -1;
}

int main()
{
	const int boss = 53;
	int ans;
	for (int i = 1; i <= n; i++)
	{
		int h = winner(i);
		printf("%i: %i\n", i, h);
		if (h == boss)
			ans = i;
	}
	printf("ans: %i\n", my_pow(ans, 1390));
}