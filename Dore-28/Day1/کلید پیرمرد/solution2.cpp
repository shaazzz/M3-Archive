#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll maxn = 1e6 + 18 , md = 229939 , inf = 2e16;

struct fentree {

	ll sz;
	vector<ll> val;

	void init(ll n){
		sz = n;
		val.assign(sz , 0);
		return;
	}

	void add(ll i){
		ll h = i;
		while(h < sz){
			val[h]++;
			h |= (h + 1);
		}
		return;
	}

	ll cal(ll i){
		ll h = i , res = 0;
		while(~h){
			res += val[h];
			h &= (h + 1); h--;
		}
		return res;
	}

	void clear(){
		val.clear();
		return;
	}

};

ll fr[maxn] , ls[maxn];

void prime(){
	for(ll i = 2 ; i < maxn ; i++){
		if(fr[i] != -1) continue;
		for(ll j = i ; j < maxn ; j += i){
			if(fr[j] == -1){
				fr[j] = i;
			}
			ls[j] = i;
		}
	}
	return;
}

ll tv[maxn];
fentree ft;
vector<ll> qu[maxn] , ind[maxn];

ll cal(ll n){
	ft.clear();
	for(ll i = 1 ; i <= n ; i++){
		qu[i].clear();
	}
	ft.init(n + 1);
	ft.add(1);
	for(ll i = 2 ; i <= n ; i++){
		ll h = n / i;
		qu[ls[i]].push_back(h);
	}
	ll res = 0;
	for(ll i = n ; i > 1 ; i--){
		for(auto j : ind[i]){
			if(j > n) break;
			ft.add(j);
		}
		for(auto j : qu[i]){
			res += tv[ft.cal(j)] - 1; res %= md;
		}
	}
	res %= md;
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	tv[0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		tv[i] = tv[i - 1] << 1; tv[i] -= (tv[i] >= md) * md;
	}
	memset(fr , -1 , sizeof(fr));
	prime();
	for(ll i = 2 ; i < maxn ; i++){
		ind[fr[i]].push_back(i);
	}
	ll n1 = 10 , n2 = 1000 , n3 = 1e6;
	ll h = cal(n1);
	h = h * h * h % md;
	cout<<h<<'\n';
	cout<<cal(n2)<<'\n';
	cout<<cal(n3)<<'\n';
	return 0;
}