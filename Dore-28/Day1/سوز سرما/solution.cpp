#include <bits/stdc++.h>
#define Loop(x,l,r) for (ll x = (l); x < (ll)(r); ++x)
#define LoopR(x,l,r) for (ll x = (r)-1; x >= (ll)(l); --x)
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll , ll > pll;
using namespace std;

#define int ll

ll idx_to_val(int n, ll i)
{
	if (n == 1)
		return i+1;
	if (i%4 == 0)
		return idx_to_val(n-1, i/4);
	ll x = 3 * (1ll << n-2) * (1ll << n-2); // 3 * 4**(n-2)
	x += (i * 3 + 3) / 4;
	return x;
}

ll val_to_idx(int n, ll x)
{
	if (n == 1)
		return x-1;
	ll dard = 3 * (1ll << n-2) * (1ll << n-2); // 3 * 4**(n-2)
	if (x <= dard)
		return val_to_idx(n-1, x) * 4;
	return ((x - dard) * 4 - 1) / 3;
}


vector<int> advance(vector<int> vec)
{
	vector<int> ans;
	int x = vec.size();
	Loop (i,0,vec.size()) {
		ans.push_back(vec[i]);
		ans.push_back(++x);
		ans.push_back(++x);
		ans.push_back(++x);
	}
	return ans;
}

ll dis(int n, ll x, ll y)
{
	ll len = 3 * (1ll << n-1) * (1ll << n-1); // 3 * 4**(n-1)
	x = val_to_idx(n, x);
	y = val_to_idx(n, y);
	if (x > y)
		swap(x, y);
	return min(y - x, len - (y - x));
}

const int mod = 229939;

ll f(int n, vector<ll> vec)
{
	ll ans = 0;
	Loop (i,0,vec.size()) Loop (j,i+1,vec.size()) {
		ans += (vec[i] % mod) * (vec[j] % mod) % mod * (dis(n, vec[i], vec[j]) % mod);
		ans %= mod;
	}
	return ans;
}

signed main()
{
	int n1 = 4, n2 = 10, n3 = 28;
	vector<ll> s1 = { 1, 3, 8, 13, 34, 89 };
	vector<ll> s2 = { 1 }; Loop (i,0,12) s2.push_back(s2.back() * 3);
	vector<ll> s3 = { 1 }; Loop (i,0,23) s3.push_back(s3.back() * 5);
	ll dard = 1;
	Loop (i,0,5)
		dard = dard * f(n1, s1) % mod;
	cout << dard << '\n';
	cout << f(n2, s2) << '\n';
	cout << f(n3, s3) << '\n';
}
