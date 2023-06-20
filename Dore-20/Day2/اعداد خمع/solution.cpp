#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll maxn = 1e6 + 18 , md = 97987 , inf = 2e16;

ll e[maxn];
bool mark[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n = 1e6;
	for(ll i = 1 ; i < n ; i++){
		for(ll j = i << 1 ; j < n ; j += i){
			e[j] += i;
		}
	}
	ll ind;
	for(ll t = 1 ; t <= 13 ; t++){
		ind = 1;
		for(ll i = 2 ; i < n ; i++){
			if(mark[i]) continue;
			if(e[i] * ind > e[ind] * i){
				ind = i;
			}
		}
		mark[ind] = true;
	}
	ll res = ind * ind * (ind + 1) % md;
	cout<<res<<'\n';
	return 0;
}