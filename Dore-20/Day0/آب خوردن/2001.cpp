#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

const ll maxn = 5e5 + 18 , md = 1e6 , dl = 10007 , inf = 2e18;

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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll a = tav(1389 , 1431) , b = 1;
	while(a > 0){
		b *= a % 10;
		a /= 10;
	}
	cout<<b % dl<<'\n';
	return 0;
}