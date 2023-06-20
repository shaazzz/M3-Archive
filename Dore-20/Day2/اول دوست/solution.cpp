#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll , ll> pll;

const ll maxn = 1389005 , md = 97987 , inf = 2e16;

bool g[maxn];

void prime(){
	fill(g + 2 , g + maxn , 1);
	for(ll i = 2 ; i < maxn ; i++){
		if(!g[i]) continue;
		for(ll j = i * i ; j < maxn ; j += i){
			g[j] = false;
		}
	}
	return;
}

vector<int> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	prime();
	ll n = 1389000 , ans = 0;
	for(ll i = 1 ; i <= n ; i++){
		ll h = i;
		v.clear();
		while(h > 0){
			v.push_back(h % 10);
			h /= 10;
		}
		reverse(v.begin() , v.end());
		ll d = v.size();
		for(ll j = 0 ; j < d ; j++){
			if(v[j] == 0) continue;
			ll h = 0;
			for(ll k = j ; k < d ; k++){
				h *= 10; h += v[k];
				ans += g[h];
			}
		}
	}
	ans %= md;
	cout<<ans<<'\n';
	return 0;
}