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

vector<int> A;
ll dpdig[10] = { 1,1,1,1,1,1,1,1,1,1 };
ll dp[delta] = {};

bool isPrime(ll p)
{
	if (p < 2)
		return false;
	for (int i = 2; i * i <= p; i++)
		if (p % i == 0)
			return false;
	return true;
}

int lef(int x)
{
	while (x > 9)
		x /= 10;
	return x;
}
int rig(int x)
{
	return x % 10;
}
int dig(int x)
{
	int ans = 0;
	while (x > 0)
	{
		ans++;
		x /= 10;
	}
	return ans;
}

int main()
{
	for (int i = 8; i < delta; i++)
		if (isPrime(i))
			A.push_back(i);
	for(int i = 0; i < A.size(); i++)
	{
		dp[i] = dpdig[lef(A[i])] + dig(A[i]) - 1;
		dpdig[rig(A[i])] = max(dpdig[rig(A[i])], dp[i]);
	}
	ll ans = 0;
	for (int x : dpdig)
		ans = max((int)ans, x);
	cout << "M: " << ans << '\n';
	cout << "M3: " << ans * ans * ans << '\n';
	cout << "M3%delta: " << ans * ans * ans % delta << '\n';
}