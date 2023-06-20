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

char hold1[2049];
char hold2[2049];
int h1, m1, s1, ms1, h2, m2, s2, ms2;
ll ans = 0;

void numtochar(int n)
{
	stack<char> s;
	while (n > 0)
	{
		s.push('0' + n % 10);
		n /= 10;
	}
	s.push('\0');
	for (int i = 0; !s.empty(); i++)
	{
		hold2[i] = s.top();
		s.pop();
	}
}
int chartonum()
{
	int ans = 0;
	for (int i = 0; hold1[i] != '\0'; i++)
	{
		ans *= 10;
		ans += hold1[i] - '0';
	}
	return ans;
}
bool isnum()
{
	for (int i = 0; hold1[i] != '\0'; i++)
		if (hold1[i] < '0' || hold1[i] > '9')
			return 0;
	return 1;
}
void calc()
{
	ans += 1;
	ans += ms2 - ms1;
	ans += 1000LL * (s2 - s1);
	ans += 60000LL * (m2 - m1);
	ans += 3600000LL * (h2 - h1);
}

FILE* f;

int main()
{
	const int s = 1076;
	f = fopen("marysub.txt", "r");
	int p = 1;
	int i = 0;
	int flag = -1;
	while (getc(f) != '1');
	ungetc('1', f);
	for (;;)
	{
		if (fscanf(f, "%c", &hold1[i]) <= 0)
			break;
		if (flag != -1)
		{
			if (hold1[i] == ':' || hold1[i] == ',' || hold1[i] == ' ' || hold1[i] == '\n' || hold1[i] == '\r')
			{
				hold1[i] = '\0';
				i = -1;
				if (isnum())
				{
					switch (flag)
					{
					case 0: h1 = chartonum(); break;
					case 1: m1 = chartonum(); break;
					case 2: s1 = chartonum(); break;
					case 3: ms1 = chartonum(); break;
					case 4: h2 = chartonum(); break;
					case 5: m2 = chartonum(); break;
					case 6: s2 = chartonum(); break;
					case 7: ms2 = chartonum(); break;
					}
					flag++;
				}
			}
		}
		else
		{
			if (hold1[i] == '\n')
			{
				hold1[i] = '\0';
				if (i > 0 && hold1[i-1] == '\r')
					hold1[i-1] = '\0';
				i = -1;
				if (isnum() && p == chartonum())
				{
					flag = 0;
					p++;
				}
			}
		}
		if (flag == 8)
		{
			calc();
			flag = -1;
		}
		i++;
	}
	cout << (ans % delta) << '\n';
}
