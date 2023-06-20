#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll , ll> pll;

const ll maxn = 2e4 + 18 , md = 10007 , inf = 2e16;

ll a[55] , d[maxn];
vector<ll> v[9] , u[9];

void f(ll x , ll y){
	ll h = x * 3 + y;
	for(ll i = 0 ; i < 9 ; i++){
		swap(a[v[h][i]] , a[v[h][i + 3]]);
	}
	if(y == 1) return;
	for(ll i = 0 ; i < 6 ; i++){
		swap(a[u[h][i]] , a[u[h][i + 2]]);
	}
	return;
}

ll cal(){
	ll res = 0;
	for(ll i = 1 ; i <= 54 ; i++){
		ll h = (i - a[i]) * (i - a[i]);
		res += h * h;
	}
	return res;
}

ll sub1(){
	iota(a + 1 , a + 55 , 1);
	for(ll i = 1 ; i <= 100 ; i++){
		f(0 , d[i]);
	}
	ll res = cal() % md;
	return res;
}

ll sub2(){
	iota(a + 1 , a + 55 , 1);
	for(ll i = 1 ; i <= 100 ; i++){
		f(d[i] , 1);
	}
	ll res = cal() % md;
	return res;
}

ll sub3(){
	iota(a + 1 , a + 55 , 1);
	for(ll i = 1 ; i <= 10000 ; i++){
		f(d[2 * i] , d[2 * i + 1]);
	}
	ll res = cal() % md;
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	v[0] = {1 , 2 , 3 , 18 , 30 , 42 , 54 , 53 , 52 , 34 , 22 , 10};
	v[1] = {4 , 5 , 6 , 17 , 29 , 41 , 51 , 50 , 49 , 35 , 23 , 11};
	v[2] = {7 , 8 , 9 , 16 , 28 , 40 , 48 , 47 , 46 , 36 , 24 , 12};
	v[3] = {37 , 25 , 13 , 7 , 4 , 1 , 21 , 33 , 45 , 52 , 49 , 46};
	v[4] = {38 , 26 , 14 , 8 , 5 , 2 , 20 , 32 , 44 , 53 , 50 , 47};
	v[5] = {39 , 27 , 15 , 9 , 6 , 3 , 19 , 31 , 43 , 54 , 51 , 48};
	for(ll i = 45 ; i > 33 ; i--){
		v[6].push_back(i);
	}
	for(ll i = 33 ; i > 21 ; i--){
		v[7].push_back(i);
	}
	for(ll i = 21 ; i > 9 ; i--){
		v[8].push_back(i);
	}
	u[0] = {21 , 20 , 19 , 31 , 43 , 44 , 45 , 33};
	u[2] = {13 , 14 , 15 , 27 , 39 , 38 , 37 , 25};
	u[3] = {12 , 11 , 10 , 22 , 34 , 35 , 36 , 24};
	u[5] = {16 , 17 , 18 , 30 , 42 , 41 , 40 , 28};
	u[6] = {48 , 47 , 46 , 49 , 52 , 53 , 54 , 51};
	u[8] = {1 , 2 , 3 , 6 , 9 , 8 , 7 , 4};
	for(ll i = 1 ; i < maxn ; i++){
		for(ll j = i ; j < maxn ; j += i){
			d[j]++;
		}
		d[i] %= 3;
	}
	cout<<sub1()<<'\n';
	cout<<sub2()<<'\n';
	cout<<sub3()<<'\n';
	return 0;
}