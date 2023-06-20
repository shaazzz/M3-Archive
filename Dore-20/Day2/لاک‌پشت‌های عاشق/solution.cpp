#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll , ll> pll;

const ll maxn = 1e6 + 18 , md = 97987 , inf = 2e16;

ll dis(pll a , pll b){
	return abs(a.first - b.first) + abs(a.second - b.second);
}

pll nw(pll a , pll b){
	pll ans;
	ll res = inf;
	for(ll i = a.first - 1 ; i <= a.first + 1 ; i++){
		for(ll j = a.second - 1 ; j <= a.second + 1 ; j++){
			ll h = dis({i , j} , b);
			if(h < res){
				res = h;
				ans = {i , j};
			}
		}
	}
	if(ans == b) ans = a;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	pll a , b , c , A , B , C;
	a = {1024 , 2010};
	b = {-1381 , 138};
	c = {1 , 2010};
	ll res = 0;
	while(true){
		A = nw(a , b);
		B = nw(b , c);
		C = nw(c , a);
		if(A == a && B == b && C == c) break;
		res++;
		a = A;
		b = B;
		c = C;
	}
//	cout<<res<<'\n';
	ll h = res * res * res % md;
	h = h * h % md;
	cout<<h<<'\n';
	return 0;
}