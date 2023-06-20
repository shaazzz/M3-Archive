#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

const ll maxn = 5e5 + 18 , md = 10007 , inf = 2e18;

ll rev(ll x){
	ll res = 0;
	while(x > 0){
		res *= 10;
		res += x % 10;
		x /= 10;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n = 13892010 , cnt = 0;
	for(ll i = 1 ; i < n ; i++){
		ll r = rev(i);
		cnt += (i % r == 0 || r % i == 0);
	}
	cnt = cnt * cnt % md;
	cout<<cnt<<'\n';
	return 0;
}