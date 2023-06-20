#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll maxn = 70 , md = 229939 , inf = 2e16;

ll tv[maxn] , dp[maxn] , pd[maxn] , g[maxn];

ll cal(ll n){
	ll res = 0;
	for(ll i = 0 ; i < n ; i++){
		ll h = 0;
		for(ll j = i ; j < n ; j++){
			if(j == i + 1) continue;
			memset(dp , 0 , sizeof(dp));
			ll o = tv[i];
			for(ll k = 1 ; k <= i + 1 ; k++){
				dp[k] = 1;
			}
			for(ll k = n - 2 ; k >= j ; k--){
				memset(pd , 0 , sizeof(pd));
				pd[i + 1] = (dp[i + 1] + 1) * (dp[i] + 1) % md;
				for(ll t = i ; t ; t--){
					pd[t] = (dp[t - 1] + 1) * (dp[t - 1] + 1) % md;
				}
				memcpy(dp , pd , sizeof(dp));
				for(ll t = 1 ; t <= i ; t++){
					o += tv[i - t] * dp[t] % md;
				}
				o += dp[i + 1];
				o %= md;
			}
			h += o * g[j - i] % md;
		}
		h *= tv[i]; h %= md;
		res += h;
	}
	res %= md;
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	tv[0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		tv[i] = tv[i - 1] << 1; tv[i] -= (tv[i] >= md) * md;
	}
	g[0] = g[2] = 1; g[1] = 0;
	for(ll i = 3 ; i < maxn ; i++){
		g[i] = tv[i - 2];
	}
	ll n1 = 4 , n2 = 16 , n3 = 64;
	ll h = cal(n1);
	h = h * h * h % md;
	cout<<h<<'\n';
	cout<<cal(n2)<<'\n';
	cout<<cal(n3)<<'\n';
	return 0;
}