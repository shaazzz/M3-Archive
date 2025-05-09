#include <bits/stdc++.h>

using namespace std;

const int n = 12;
typedef long long ll;

const int mod = 26003;

ll po(ll b, ll p){
	return (p == 0 ? 1 : po(b*b%mod, p/2) * (p & 1 > 0 ? b : 1) % mod);
}

ll m2[n+1], m1[n+1]; // m[i] = ans if numbers where 0, 1, .. 2^(i)-1

signed main(){
	m2[0] = 0;
	m2[1] = 2;
	m1[0] = 0;
	m1[1] = 2;
	for(int i = 2; i <= n; i++){
        // what numbers will go up at least once? (greedy)
        // numbers in range [2^(i-1), 2^i-1] for m2
		m1[i] = m1[i-1]*2 + (po(2, i)-1) + po(2, i-1) * (po(2, i)-1) % mod;
		m1[i] %= mod;
        // odd numbers only
		m2[i] = m2[i-1] + (po(2, i)-1) * (po(2, i-1)) % mod + po(2, i-1) * (po(2, i)-1) % mod;
		m2[i] %= mod;
	}
	cout << m1[n] << ' ' << m2[n] << '\n';
	ll mm = (m1[n] * m2[n]) % mod;
	mm = mm * mm % mod;
	cout << mm << '\n';
}

/*
m2[2] = 14
3
3 2
3 1 2 0

m1[2] = 13
3
3 1
3 2 1 0
*/