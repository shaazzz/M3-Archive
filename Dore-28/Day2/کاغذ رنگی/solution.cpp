#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

typedef long long int ll;

const ll maxn = 1e5 + 18 , md = 229939;

inline ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k >>= 1;
	}
	return res;
}

ll fact[maxn] , _fact[maxn];

void fact_build(){
	fact[0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		fact[i] = fact[i - 1] * i % md;
	}
	_fact[maxn - 1] = tav(fact[maxn - 1] , md - 2);
	for(ll i = maxn - 2 ; ~i ; i--){
		_fact[i] = _fact[i + 1] * (i + 1) % md;
	}
	return;
}

ll chs(ll n , ll k){
	if(k < 0 || k > n) return 0;
	return fact[n] * _fact[k] % md * _fact[n - k] % md;
}

ll cal(ll n , ll k){
	ll res = (n + k - 1) / k * fact[n];
	for(ll i = 2 ; i <= n ; i++){
		ll o = 0;
		for(ll j = 1 ; j <= n - i + 1 ; j++){
			ll h = chs(n - j - 1 , i - 2) * ((j + k - 1) / k);
			o += h;
		}
		o = o % md * fact[i - 1] % md * i % md * fact[n - i + 1] % md;
		res += o;
	}
	res %= md;
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fact_build();
	ll n1 = 10 , k1 = 4 , n2 = 100 , k2 = 43 , n3 = 1e4 , k3 = 400;
	cout<<cal(n1 , k1)<<'\n';
	cout<<cal(n2 , k2)<<'\n';
	cout<<cal(n3 , k3)<<'\n';
	return 0;
}