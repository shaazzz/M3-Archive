#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll , ll> pll;

const ll maxn = 12299390 , md = 229939 , inf = 2e16;

bool g[maxn];
int pr[maxn] , fi[maxn] , cnt[maxn];
ll dp[maxn];

void prime(){
	fill(g + 2 , g + maxn , 1);
	for(ll i = 2 ; i < maxn ; i++){
		if(!g[i]) continue;
		pr[i] = i;
		for(ll j = i * i ; j < maxn ; j += i){
			g[j] = false;
			pr[j] = i;
		}
	}
	fi[1] = 1;
	for(ll i = 2 ; i < maxn ; i++){
		int o = i;
		while(o % pr[i] == 0) o /= pr[i];
		fi[i] = i / o; fi[i] /= pr[i]; fi[i] *= (pr[i] - 1) * fi[o];
	}
	dp[1] = 1;
	for(ll i = 2 ; i < maxn ; i++){
		dp[i] = dp[i - 1] + 2 * fi[i]; dp[i] %= md;
	}
	return;
}

ll sub1(){
	ll a = dp[md - 1];
	a = a * a * a % md * a % md;
	return a;
}

ll tav(ll n , ll k){
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

ll sub2(){
	ll b = 0;
	for(ll i = 1 ; i < md ; i++){
		if(cnt[i] != 48) continue;
		ll h = (md - 1) / i;
		b += dp[h];
	}
	b %= md;
	return tav(b , b);
}

ll sub3(){
	ll res = 0;
	for(ll i = 1 ; i < maxn ; i++){
		if(cnt[i] != 48) continue;
		ll h = (maxn - 1) / i;
		res += dp[h];
	}
	res %= md;
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	prime();
	for(ll i = 1 ; i < maxn ; i++){
		for(ll j = i ; j < maxn ; j += i){
			cnt[j]++;
		}
	}
	cout<<sub1()<<'\n';
	cout<<sub2()<<'\n';
	cout<<sub3()<<'\n';
	return 0;
}