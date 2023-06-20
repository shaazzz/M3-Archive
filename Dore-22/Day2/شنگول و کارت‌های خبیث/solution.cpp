#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll , ll> pll;

const ll maxn = 1e3 , md = 11287 , inf = 2e16;

vector<ll> v;
ll d[] = {1 , 1 , 2 , 2 , 3 , 3 , 3 , 3 , 4 , 4 , 4};
set<ll> s;

ll sub3(){
	string s = "100001000100100110101010110111100110110111101111111111";
	ll x = 0;
	for(ll i = 0 ; i < 54 ; i++){
		x <<= 1; x += s[i] ^ '0';
	}
	ll res = 2 * 24 * x % md;
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for(ll i = 1 ; i <= 10 ; i++){
		v.push_back(i);
	}
	ll cnt = 0;
	do {
		ll h = 0 , cur = 0;
		for(ll i = 0 ; i < 10 ; i++){
			h += v[i] * (1ll << cur);
			cur += d[v[i]];
		}
		s.insert(h);
	} while(next_permutation(v.begin() , v.end()));
	auto it = s.end(); it--;
	ll res = *s.begin() * *it % md;
	cout<<res<<'\n';
	res = (1 << 29) - s.size(); res = res * res % md;
	cout<<res<<'\n';
	cout<<sub3()<<'\n';
	return 0;
}