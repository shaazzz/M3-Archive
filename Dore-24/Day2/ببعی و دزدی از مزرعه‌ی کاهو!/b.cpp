#include <bits/stdc++.h>
#define dbg(x) cout << #x << ": " << x << '\n';

using namespace std;

typedef long long ll;

const int mod = 10847;

ll po(ll b, ll p){
	return (p == 0 ? 1 : po(b*b%mod, p/2) * (p&1 ? b : 1)) % mod;
}

const int n = 10;
ll fac[n+1];
ll bs;

int cal(int i, int d, ll f){ // sum of i, i+d, ... <= n!
	// assert(0 <= i && i < d);
	ll sm = 0;
	for(int j = i; j <= f; j += d) sm += j;
	return sm;
}

ll fact(int n){
	ll r = 1;
	for(ll i = 2; i <= n; i++) r *= i;
	return r;
}

// void bf(){
// 	int a[fact(n)+1], b[fact(n)+1];
// 	for(int i = 1; i <= fact(n); i++)a[i] = i;
// 	for(int i = 1; i <= n; i++){
// 		int x = fact(i);
// 		for(int j = 1; j <= fact(n); j++){
// 			b[(j+x-1)%fact(n)+1] = a[j];
// 		}
// 		for(int j = 1; j <= fact(n); j++){
// 			a[j] = b[j];
// 		}
// 	}
// 	for(int i = 1; i <= fact(n); i++) cout << a[i] << ' ';
// 	cout << '\n';
// }

signed main(){
	// bf();
	fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = fac[i-1] * i;
	bs = (fac[n] + 3) % mod;
	ll w = 1;
	int ans = 0;
	ll q = 0;
	for(int i = 1; i < n; i++) q += fact(i);
	dbg(q);
	int ind1 = q % (mod-1);
	for(int i = 0; i < fact(n); i++){
		ll ml = po(bs, (fact(n)-i-1)%(mod-1));
		ll le = cal(fact(n)-q+1+i, mod-1, fact(n));
		ll re;
		if(ind1 <= i) re = cal(i-ind1 + 1, mod-1, fact(n)-q);
		else re = cal(i-ind1 + 1 + mod-1, mod-1, fact(n)-q);
		ans += ml * (le + re) % mod;
		ans %= mod;
		cout << i << " : " << ml << ' ' << le << ' ' << re << endl;
		w = w * bs % mod;
		if(w == 1) {
			cout << i << '\n';
			assert(i == mod-2);
			break;
		}
	}
	dbg(ans);
}

/*

*/