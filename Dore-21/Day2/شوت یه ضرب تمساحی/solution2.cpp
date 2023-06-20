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
const int n = 9;

int hap[n][n] = {};
int x = 0, y = 0;

void shoot()
{
	switch (hap[x][y]++ % 4)
	{
	case 0: y = (8 + y) % 9; break;
	case 1: x = (1 + x) % 9; break;
	case 2: y = (1 + y) % 9; break;
	case 3: x = (8 + x) % 9; break;
	}
}

int main()
{
	for (int i = 1; i < delta; i++)
		shoot();
	ll sum = 0;
	ll pro = 1;
	Loop(i,0,n)
		Loop(j, 0, n)
		{
			sum += hap[i][j];
			pro *= hap[i][j];
			pro %= delta;
		}
	printf("sum: %lli\n", sum);
	printf("ans: %lli\n", pro);
}
