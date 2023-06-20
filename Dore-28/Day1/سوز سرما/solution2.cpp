#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll maxn = 30 , md = 229939 , inf = 2e16;

ll t[maxn] , tv[maxn];

ll g(ll n , ll a){
	if(a <= 3) return (a - 1) * tv[n - 1];
	ll res;
	for(ll j = n - 1 ; j ; j--){
		if(a > t[j]){
			ll h = a - t[j];
			res = h + (h - 1) / 3;
			res *= tv[n - j - 1];
			return res;
		}
	}
	return 0;
}

ll d(ll n , ll a , ll b){
	ll fa = g(n , a) , fb = g(n , b);
	return min(abs(fa - fb) , t[n] - abs(fa - fb));
}

ll f(ll n , ll a[] , ll m){
	ll res = 0;
	for(ll i = 0 ; i < m ; i++){
		for(ll j = i + 1 ; j < m ; j++){
			res += (a[i] % md) * (a[j] % md) % md * (d(n , a[i] , a[j]) % md) % md;
		}
	}
	res %= md;
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	tv[0] = 1;
	for(ll i = 1 ; i < 30 ; i++){
		tv[i] = tv[i - 1] * 4;
	}
	t[1] = 3;
	for(ll i = 2 ; i < 30 ; i++){
		t[i] = t[i - 1] * 4;
	}
	ll n1 = 4 , a1[] = {1 , 3 , 8 , 13 , 34 , 89} , m1 = 6;
	ll h = f(n1 , a1 , m1);
	h = h * h * h % md * h * h % md;
	cout<<h<<'\n';
	ll n2 = 10 , m2 = 13 , a2[13];
	a2[0] = 1;
	for(ll i = 1 ; i < m2 ; i++){
		a2[i] = a2[i - 1] * 3;
	}
	cout<<f(n2 , a2 , m2)<<'\n';
	ll n3 = 28 , m3 = 24 , a3[24];
	a3[0] = 1;
	for(ll i = 1 ; i < m3 ; i++){
		a3[i] = a3[i - 1] * 5;
	}
	cout<<f(n3 , a3 , m3)<<'\n';
	return 0;
}