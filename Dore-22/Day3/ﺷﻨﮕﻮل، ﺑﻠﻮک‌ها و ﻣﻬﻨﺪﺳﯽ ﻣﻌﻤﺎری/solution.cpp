#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll , ll> pll;

const ll maxn = 1e3 , md = 229939 , inf = 2e16;

vector<bool> v;

ll sub1(){
	ll lm = (1 << 8) , res = 1;
	for(ll i = 2 ; i < lm ; i++){
		v.clear();
		ll h = i;
		while(h > 0){
			v.push_back(h & 1);
			h >>= 1;
		}
		ll d = v.size();
		for(ll j = 1 ; j < d ; j++){
			if(d % j != 0) continue;
			bool t = true;
			for(ll k = 0 ; k < d - j ; k++){
				t &= (v[k] == v[k + j]);
			}
			if(t){
				res *= i; res %= md;
				break;
			}
		}
	}
	return res;
}

ll dp[50] , pd[50];

ll sub2(){
	ll res = 0;
	for(ll i = 1 ; i <= 24 ; i++){
		res += dp[i];
	}
	res %= md;
	return res;
}

ll sub3(){
	ll res = 0;
	for(ll i = 1 ; i <= 48 ; i++){
		res += dp[i];
	}
	res %= md;
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	dp[1] = 0; pd[1] = 1;
	for(ll i = 2 ; i <= 48 ; i++){
		for(ll j = 1 ; j < i ; j++){
			if(i % j != 0) continue;
			dp[i] += pd[j];
		}
		dp[i] %= md;
		pd[i] = (1ll << (i - 1)) - dp[i]; pd[i] %= md;
	}
	cout<<sub1()<<'\n';
	cout<<sub2()<<'\n';
	cout<<sub3()<<'\n';
	return 0;
}