#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll , ll> pll;

const ll maxn = 1e3 , md = 229939 , inf = 2e16;

int a[] = {972, -1, 273, -1, 932, 911, -1, 233};
int b[] = { -1, 942, 135, -1, 371, -1, 311, -1};

int dp[10][maxn];

ll sub1(){
	ll res = dp[2][777];
	for(ll i = 2 ; i < 8 ; i++){
		if(a[i] == -1){
			res *= 900; res %= md;
		}
		if(b[i] == -1){
			res *= 900; res %= md;
		}
	}
	return res;
}

ll sub2(){
	ll res = dp[4][777];
	for(ll i = 4 ; i < 8 ; i++){
		if(a[i] == -1){
			res *= 900; res %= md;
		}
		if(b[i] == -1){
			res *= 900; res %= md;
		}
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	dp[0][777] = 1;
	for(ll i = 0 ; i < 8 ; i++){
		for(ll j = 0 ; j <= 999 ; j++){
			for(ll k = 100 ; k <= 999 ; k++){
				if(a[i] != -1) k = a[i];
				for(ll q = 100 ; q <= 999 ; q++){
					if(b[i] != -1) q = b[i];
					ll c = (j * k + i + 1) % q;
					dp[i + 1][c] += dp[i][j]; dp[i + 1][c] -= (dp[i + 1][c] >= md) * md;
					if(b[i] != -1) break;
				}
				if(a[i] != -1) break;
			}
		}
	}
	cout<<sub1()<<'\n';
	cout<<sub2()<<'\n';
	cout<<dp[8][777]<<'\n';
	return 0;
}