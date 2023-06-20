#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

typedef long long int ll;

const ll maxn = 497 , md = 229939;

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

ll a[maxn] , b[maxn] , c[maxn] , as = 497 , bs = 249 , cs = 125 , sz;
vector<ll> f;
ll fs , sum , dv;

ll cal(ll i){
	ll ans = i , t , h;
	t = i / fs;
	h = t * sum % md;
	ans += h;
	h = sz % md * fs % md * t % md * (t - 1) % md * dv % md;
	ans += h;
	ll r = i % fs;
	h = sz * t % md * r % md;
	ans += h;
	for(ll j = 0 ; j < r ; j++){
		ans += f[j];
	}
	ans %= md;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	dv = tav(2 , md - 2);
	for(ll i = 0 ; i < as ; i++){
		a[i] = i + 1;
	}
	for(ll i = 0 ; i < bs ; i++){
		b[i] = a[2 * i];
	}
	for(ll i = 0 ; i < cs ; i++){
		c[i] = b[2 * i];
	}
	reverse(b + 1 , b + bs);
	ll ax = 0 , bx = 0 , cx = 0;
	sz = as * bs * cs;
	for(ll i = 0 ; i < sz ; i++){
		if(b[bx] % c[cx] == 0 && a[ax] % b[bx] == 0){
			f.push_back(i);
			sum += i;
			cout<<i + 1<<' ';
			fs++;
		}
		ax++; bx++; cx++;
		ax -= (ax == as) * as;
		bx -= (bx == bs) * bs;
		cx -= (cx == cs) * cs;
	}
	cout<<'\n';
	sum %= md;
	ll n1 = 10 , n2 = 1e3 , n3 = 1e12;
	ll h = cal(n1);
	h = h * h % md * h % md;
	cout<<h<<'\n';
	cout<<cal(n2)<<'\n';
	cout<<cal(n3)<<'\n';
	return 0;
}