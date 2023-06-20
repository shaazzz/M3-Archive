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

const int delta = 10007;
const int n = 13892010;

int reverse(int x)
{
	int ans = 0;
	while (x > 0)
	{
		ans *= 10;
		ans += x % 10;
		x /= 10;
	}
	return ans;
}

int main()
{
	ll T = 0;
	for (int i = 1; i < n; i++)
	{
		int r = reverse(i);
		if (i % r == 0 || r % i == 0)
			T++;
	}
	cout << "T: " << T << '\n';
	cout << "T2 % delta: " << T * T % delta << '\n';
}
