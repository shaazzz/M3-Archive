#include <iostream>

using namespace std;

typedef long long int ll;

const ll maxn = 1500 , md = 10427 , inf = 2e16;

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

ll fact[maxn] , _fact[maxn];

void fact_build(){
	fact[0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		fact[i] = fact[i - 1] * i % md;
	}
	_fact[maxn - 1] = tav(fact[maxn - 1] , md - 2);
	for(ll i = maxn - 2 ; ~i ; i--){
		_fact[i] = _fact[i + 1] * (i + 1) % md;
	}
	return;
}

ll chs(ll n , ll k){
	if(k < 0 || k > n) return 0;
	return fact[n] * _fact[k] % md * _fact[n - k] % md;
}

ll dp1[25][3][3];

ll sub1(){
	ll n = 10 , w = 100;
	n <<= 1;
	dp1[0][2][2] = 1;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j <= 2 ; j++){
			for(ll k = 0 ; k <= 2 ; k++){
				if(k < 2 && j == 2) continue;
				dp1[i][j][k] %= md;
				ll x = 0 , d = dp1[i][j][k];
				x = (j != 2) + (k != 2);
				if(x > 1) dp1[i + 1][j][2] += d;
				if(x > 0) dp1[i + 1][k][2] += d;
				if(x == 0){
					dp1[i + 1][0][2] += d;
				} else if(x == 1){
					dp1[i + 1][j + 1][1] += d;
				}
			}
		}
	}
	ll res = dp1[n][2][2] * fact[n >> 1] % md * chs(w + 1 , n) % md;
	return res;
}

ll dp2[105][4][4][4];

ll sub2(){
	ll n = 50 , w = 400;
	n <<= 1;
	dp2[0][3][3][3] = 1;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j <= 3 ; j++){
			for(ll k = 0 ; k <= 3 ; k++){
				if(j == 3 && k < 3) continue;
				for(ll t = 0 ; t <= 3 ; t++){
					if(k == 3 && t < 3) continue;
					dp2[i][j][k][t] %= md;
					ll d = dp2[i][j][k][t];
					ll x = 0;
					x = (j != 3) + (k != 3) + (t != 3);
					if(x > 0) dp2[i + 1][k][t][3] += d;
					if(x > 1) dp2[i + 1][j][t][3] += d;
					if(x > 2) dp2[i + 1][j][k][3] += d;
					if(x == 0){
						dp2[i + 1][0][3][3] += d;
					} else if(x == 1){
						dp2[i + 1][j + 1][1][3] += d;
					} else if(x == 2){
						dp2[i + 1][j + 1][k + 1][2] += d;
					}
				}
			}
		}
	}
	ll res = dp2[n][3][3][3] * fact[n >> 1] % md * chs(w + 1 , n) % md;
	return res;
}

ll dp3[206][5][5][5][5];

ll sub3(){
	ll w = 1000 , n = 100;
	n <<= 1;
	dp3[0][4][4][4][4] = 1;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j <= 4 ; j++){
			for(ll k = 0 ; k <= 4 ; k++){
				if(j == 4 && k < 4) continue;
				for(ll t = 0 ; t <= 4 ; t++){
					if(k == 4 && t < 4) continue;
					for(ll q = 0 ; q <= 4 ; q++){
						if(t == 4 && q < 4) continue;
						dp3[i][j][k][t][q] %= md;
						ll d = dp3[i][j][k][t][q];
						ll x = (j != 4) + (k != 4) + (t != 4) + (q != 4);
						if(x > 0) dp3[i + 1][k][t][q][4] += d;
						if(x > 1) dp3[i + 1][j][t][q][4] += d;
						if(x > 2) dp3[i + 1][j][k][q][4] += d;
						if(x > 3) dp3[i + 1][j][k][t][4] += d;
						if(x == 0){
							dp3[i + 1][0][4][4][4] += d;
						} else if(x == 1){
							dp3[i + 1][j + 1][1][4][4] += d;
						} else if(x == 2){
							dp3[i + 1][j + 1][k + 1][2][4] += d;
						} else if(x == 3){
							dp3[i + 1][j + 1][k + 1][t + 1][3] += d;
						}
					}
				}
			}
		}
	}
	ll res = dp3[n][4][4][4][4] * fact[n >> 1] % md * chs(w + 1 , n) % md;
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fact_build();
	cout<<sub1()<<'\n';
	cout<<sub2()<<'\n';
	cout<<sub3()<<'\n';
	return 0;
}