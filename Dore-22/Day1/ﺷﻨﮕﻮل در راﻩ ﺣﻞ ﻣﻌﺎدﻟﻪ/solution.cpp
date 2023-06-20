#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll , ll> pll;

const ll maxn = 1e3 , maxg = 1024 , md = 46639 , inf = 2e16;

ll gcd(ll a , ll b){
	if(b > a) swap(a , b);
	while(b > 0){
		ll c = a % b;
		a = b; b = c;
	}
	return a;
}

set<ll> s;

ll sub1(){
	for(ll i = 1 ; i <= 10 ; i++){
		for(ll j = 1 ; j <= 10 ; j++){
			for(ll k = 1 ; k <= 10 ; k++){
				for(ll q = 1 ; q <= 10 ; q++){
					ll h = gcd(i | j , k) ^ q;
					s.insert(h);
				}
			}
		}
	}
	ll t = s.size() , o = t;
	for(ll i = 1 ; i < 9 ; i++){
		o *= t; o %= md;
	}
	return o;
}

vector<ll> pr;
bool g[maxn];
ll gc[maxg][maxg];

ll sub2(){
	fill(g + 2 , g + maxn , 1);
	for(ll i = 2 ; i < maxn ; i++){
		if(!g[i]) continue;
		pr.push_back(i);
		for(ll j = i * i ; j < maxn ; j += i){
			g[j] = false;
		}
	}
	for(ll i = 1 ; i < maxg ; i++){
		for(ll j = 1 ; j < maxg ; j++){
			gc[i][j] = gcd(i , j);
		}
	}
	ll x = 0 , y = inf;
	for(auto i : pr){
		for(auto j : pr){
			for(auto k : pr){
				for(auto q : pr){
					ll h = gc[i | j][k] ^ q;
					x = max(x , h);
					y = min(y , h);
				}
			}
		}
	}
	ll res = x * x + y * y * y % md * y;
	res %= md;
	return res;
}

ll sub3(){
	ll w = 1;
	while(w < md) w <<= 1;
	w--;
	w *= 7; w %= md;
	return w;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cout<<sub1()<<'\n';
	cout<<sub2()<<'\n';
	cout<<sub3()<<'\n';
	return 0;
}