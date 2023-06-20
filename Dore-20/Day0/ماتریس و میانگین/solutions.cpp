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
#define Kill(x) {cout << x << '\n'; return 0;}
using namespace std;

const int delta = 10007;
const int n = 1000;
int g[2][n][n];

bool valid(int i, int j)
{
	if (i < 0 || j < 0 || i >= n || j >= n)
		return false;
	return true;
}

bool Do(int i, int j, bool k)
{
	int cnt = 0, ans = 0;

	
	for (int x = i-1; x <= i+1; ++x) for (int y = j-1; y <= j+1; ++y) {
		if (valid(x, y))
		{
			++cnt;
			ans += g[k][x][y];
		}
	}

	ans /= cnt;
	g[!k][i][j] = ans;
	return ans != g[k][i][j];
}
bool Do_mid(int i, int j, bool k)
{
	int ans = 0;

	
	for (int x = i-1; x <= i+1; ++x) for (int y = j-1; y <= j+1; ++y)
		ans += g[k][x][y];

	ans /= 9;
	g[!k][i][j] = ans;
	return ans != g[k][i][j];
}

bool Update(bool k)
{
	bool ans = 0;
	for (int i = 0; i < n; ++i) {
		ans |= Do(0, i, k);
		ans |= Do(i, 0, k);
		ans |= Do(n-1, i, k);
		ans |= Do(i, n-1, k);
	}
	for(int i = 1; i < n-1; ++i)
		for (int j = 1; j < n-1; ++j)
			ans |= Do_mid(i, j, k);
	return ans;
}

void Print(bool k)
{
	Loop(i, 0, n)
	{
		Loop(j, 0, n)
			printf("%i ", g[k][i][j]);
		printf("\n");
	}
	printf("\n");
}

void init()
{
	Loop(i, 0, n)
		Loop(j, 0, n)
			g[0][i][j] = (i + 1) * (j + 1);
}

int main()
{
	auto st = time(0);
	init();
	ll ans = 0;
	for (int i = 0;; i++)
	{
		if (!(i & 1023))
			printf("%i!\n", i);
		//Print(i & 1);
		if (!Update(i & 1))
		{
			ans = i + 1;
			break;
		}
	}
	printf("J  : %lli\n", ans);
	printf("J3 : %lli\n", ans * ans * ans);
	ans %= delta;
	printf("J3%%delta: %lli\n", (ans * ans % delta) * ans % delta);
	printf("time: %i\n", (int)difftime(time(0), st));
}
