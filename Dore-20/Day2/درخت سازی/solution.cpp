#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll , ll> pll;

const ll maxn = 1e6 , md = 97987 , inf = 2e16;

ll tr[maxn][2];
vector<bool> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(tr , -1 , sizeof(tr));
	for(ll i = 1389 ; i <= 2010 ; i++){
		for(ll j = 10 ; ~j ; j--){
			v.push_back(i & (1 << j));
		}
	}
	ll n = 1 , l = 1 , vs = v.size() , c = 0;
	for(ll i = 0 ; i < vs ; i++){
		bool k = v[i];
		if(tr[c][k] == -1){
			l += (tr[c][!k] != -1);
			tr[c][k] = n++;
			c = 0;
		} else {
			c = tr[c][k];
		}
	}
	ll ans = n * l * n * l % md;
	cout<<ans<<'\n';
	return 0;
}