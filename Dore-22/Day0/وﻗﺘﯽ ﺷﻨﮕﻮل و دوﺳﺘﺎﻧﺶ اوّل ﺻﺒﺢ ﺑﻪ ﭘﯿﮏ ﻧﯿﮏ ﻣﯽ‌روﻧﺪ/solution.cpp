#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll , ll> pll;

const ll maxn = 2e4 + 18 , md = 229939 , inf = 2e16;

bool g[md];

void prime(){
	fill(g + 2 , g + md + 1 , 1);
	for(ll i = 2 ; i <= md ; i++){
		if(!g[i]) continue;
		for(ll j = i * i ; j <= md ; j += i){
			g[j] = false;
		}
	}
	return;
}

ll sub1(){
	ll res = 0;
	for(ll i = 0 ; i <= md ; i++){
		res += g[i];
	}
	return res;
}

ll sub2(){
	ll res = 0;
	for(ll i = 1 ; i <= md ; i++){
		res += (g[i] && !g[i - 1]);
	}
	res <<= 1;
	return res;
}

ll sub5(){
	return (md / 2 + 1) * (md / 2 + 1) % 200012;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	prime();
	ll h = sub1();
	cout<<h<<'\n';
	cout<<sub2()<<'\n';
	cout<<h<<'\n';
	cout<<md + 1 - h<<'\n';
	cout<<sub5()<<'\n';
	cout<<"1\n";
	return 0;
}