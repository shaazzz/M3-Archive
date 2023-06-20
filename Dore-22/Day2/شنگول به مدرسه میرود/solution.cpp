#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll , ll> pll;

const ll maxn = 1e3 , md = 11287 , inf = 2e16;

ll x , y , d;

void op(ll i){
	ll h = i;
	while(!(h & 1)){
		h >>= 1;
		d++;
	}
	d %= 4;
	if(d == 0){
		y += h;
	} else if(d == 1){
		x += h;
	} else if(d == 2){
		y -= h;
	} else {
		x -= h;
	}
	return;
}

ll sub1(){
	x = y = d = 0;
	for(ll i = 1 ; i <= 20 ; i++){
		op(i);
	}
	ll h = x * y , res = h;
	for(ll i = 1 ; i < 9 ; i++){
		res *= h; res %= md;
	}
	res += (res < 0) * md;
	return res;
}

ll sub2(){
	x = y = d = 0;
	ll lm = md * md;
	for(ll i = 1 ; i <= lm ; i++){
		op(i);
	}
	x %= md; y %= md;
	ll res = x * y + x + y;
	res %= md; res += (res < 0) * md;
	return res;
}

ll sub3(){
	ll ans = 5e4;
	for(ll k = 1 ; k < ans ; k++){
		x = y = d = 0;
		for(ll i = 1 ; i < ans ; i++){
			if(i == k){
				d = 2;
				continue;
			}
			op(i);
			if(x == -66 && (y & 1)){
				ans = i;
				break;
			}
		}
	}
	ans = ans * ans % md;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cout<<sub1()<<'\n';
	cout<<sub2()<<'\n';
	cout<<sub3()<<'\n';
	return 0;
}