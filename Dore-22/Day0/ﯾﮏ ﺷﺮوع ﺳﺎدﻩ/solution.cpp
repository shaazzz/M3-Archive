#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll , ll> pll;

const ll maxn = 2e5 , md = 229939 , inf = 2e16;

ll a[maxn] , b[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	a[0] = 1377;
	ll x = 1 , k = 1e10;
	for(ll e = 1 ; e < md ; e++){
//		if(e % 1000 == 0){
//			cout<<x<<endl;
//		}
		for(ll i = 0 ; i <= x ; i++){
			b[i] = 0;
		}
		for(ll i = 0 ; i < x ; i++){
			b[i] += a[i] * 1377;
			b[i + 1] += b[i] / k;
			b[i] %= k;
		}
		for(ll i = 0 ; i <= x ; i++){
			a[i] = b[i];
		}
		if(a[x] > 0) x++;
	}
	cout<<a[0] % 100<<'\n';
	ll sum = 0;
	for(ll i = 0 ; i < x ; i++){
		ll h = a[i];
		while(h > 0){
			sum += h % 10;
			h /= 10;
		}
		if(i == 1){
			cout<<sum<<'\n';
		}
	}
	cout<<sum<<'\n';
	return 0;
}