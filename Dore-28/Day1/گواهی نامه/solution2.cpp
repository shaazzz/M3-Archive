#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll maxn = 3000 , md = 229939 , inf = 2e16;

ll tv[maxn] , lm = 2500;

ll sub1(){
	ll ans = 0;
	for(ll i = 1 ; i <= 50 ; i++){
		for(ll j = 1 ; j <= 50 ; j++){
			ans += tv[lm - (i + j - 1)];
		}
	}
	ans <<= 2; ans %= md;
	return ans;
}

ll sub2(){
	ll ans = 0;
	for(ll i = 1 ; i <= 50 ; i++){
		for(ll k = 1 ; k < i ; k++){
			for(ll j = 1 ; j <= 50 ; j++){
				ll h = j * (i - k + 1) , res = 1;
				for(ll t = 1 ; t < j ; t++){
					res *= tv[i - k - 1] - 1; res %= md;
				}
				res *= tv[lm - h]; res %= md;
				ans += res;
			}
		}
	}
	ans <<= 2; ans %= md;
	return ans;
}

ll dp[52][52];

ll sub3(){
	dp[1][1] = 1;
	for(ll i = 2 ; i < 50 ; i++){
		dp[1][i] = dp[i][1] = 0;
	}
	for(ll i = 2 ; i < 50 ; i++){
		for(ll j = 2 ; j < 50 ; j++){
			dp[i][j] = tv[i * j - (i + j - 1)];
			for(ll k = 1 ; k <= i ; k++){
				for(ll t = 1 ; t <= j ; t++){
					if(k == i && t == j) break;
					ll h = k * t + i + j - 1;
					if(k == i){
						h -= t;
					}
					if(t == j){
						h -= k;
					}
					ll o = tv[i * j - h] * dp[k][t] % md;
					dp[i][j] -= o;
				}
			}
			dp[i][j] %= md; dp[i][j] += (dp[i][j] < 0) * md;
		}
	}
	ll ans = 0;
	for(ll i = 2 ; i <= 50 ; i++){
		for(ll j = 1 ; j < 50 ; j++){
			for(ll k = 1 ; k < i ; k++){
				for(ll t = j + 1 ; t <= 50 ; t++){
					ll h = (i - k + 1) * (t - j + 1) + 50 - i + j - 1;
					ans += tv[lm - h] * dp[i - k][t - j] % md;
				}
			}
		}
	}
	ans <<= 2;
	ans %= md;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	tv[0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		tv[i] = tv[i - 1] << 1; tv[i] -= (tv[i] >= md) * md;
	}
	cout<<sub1()<<'\n';
	cout<<sub2()<<'\n';
	cout<<sub3()<<'\n';
	return 0;
}