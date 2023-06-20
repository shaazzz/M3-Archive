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
const int n = 100000000;

bool isPrime[n];
int cnt[n] = {};

void gharbal()
{
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[0] = false; isPrime[1] = false;
	for (int i = 2; i*i < n; i++)
	{
		if (!isPrime[i])
			continue;
		for (int j = i * i; j < n; j += i)
			isPrime[j] = false;
	}
}

int main()
{
	gharbal();
	for (int i = 1; i < n; i++)
	{
		if (!isPrime[i])
			continue;
		for (int j = i; j < n; j += i)
			cnt[j]++;
	}

	ll ans = 0;
	for (int i = 2; i < n; i++)
	{
		if (cnt[i] == i % 10)
			ans += i;
	}
	printf("ans: %lli\n", ans);
	printf("ans%%delta: %lli\n", ans % delta);
}
