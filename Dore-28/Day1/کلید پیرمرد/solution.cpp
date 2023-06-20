#include <bits/stdc++.h>
#define Loop(x,l,r) for (ll x = (l); x < (ll)(r); ++x)
#define LoopR(x,l,r) for (ll x = (r)-1; x >= (ll)(l); --x)
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll , ll > pll;
using namespace std;

const int mod = 229939;

ll Do(int n)
{
	vector<vector<int>> vec(n+1);
	vector<ll> p2 = {1};
	Loop (i,0,n)
		p2.push_back(p2.back()*2 % mod);
	for (int x = 2; x <= n; ++x) {
		if (vec[x].size())
			continue;
		for (int y = x; y <= n; y += x) {
			for (int z = y; z % x == 0; z /= x)
				vec[y].push_back(x);
		}
	}
	set<vector<int>> s;
	ll ans = 0;
	for (int x = 2; x <= n; ++x) {
		//if (x%1001 == 0)
		//	cerr << x << '\n';
		Loop (len,1,vec[x].size()+1) {
			vector<int> v = vec[x];
			while (v.size() != len)
				v.pop_back();
			if (!s.insert(v).second)
				continue;
			int x = 1;
			for (int y : v)
				x *= y;
			int cnt = 0;
			for (int i = x; i <= n; i += x)
				cnt += vec[i].size() >= len && memcmp(vec[i].data(), v.data(), len * sizeof(v[0])) == 0;
			ans += p2[cnt]+mod-1;
			ans %= mod;
		}
	}
	return ans;
}

int main()
{
	cout << Do(10) * Do(10) % mod * Do(10) % mod << '\n';
	cout << Do(1000) << '\n';
	cout << Do(1e6) << '\n';
}
