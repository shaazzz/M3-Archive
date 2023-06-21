#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll , ll> pll;

const ll maxn = 2e4 + 18 , md = 11287 , inf = 2e16;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll res = 1 , lm = md * md + 1;
	while(res < lm) res <<= 1;
	res >>= 1;
	res = res * res * 3 % md;
	cout<<res<<'\n';
	ll cur = 2 , ans = 0;
	while((cur << 1) < lm){
		ll r = cur >> 1;
		ans += r * r * 3 % md;
		cur <<= 1;
	}
	ll q = lm - cur , h = 1;
	while(h <= q) h <<= 1;
	h >>= 1;
	ans += h * h * 3 % md;
	ans %= md;
	cout<<ans<<'\n';
	lm -= 2;
	res = 0;
	for(ll j = 1 ; j < 50 ; j++){
		if((1ll << j) & lm){
			res += 3 * (1ll << (j - 1)) * (1ll << (j - 1)) % md;
		}
	}
	res %= md;
	cout<<res<<'\n';
	return 0;
}