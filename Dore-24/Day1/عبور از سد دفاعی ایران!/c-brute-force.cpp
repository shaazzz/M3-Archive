#include <bits/stdc++.h>
#define ff first
#define ss second
#define dbg(x) cout << #x << ": " << x << '\n';

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int mod = 26003;

ll po(ll b, ll p){
	return (p == 0 ? 1 : po(b*b%mod, p/2) * (p & 1 > 0 ? b : 1) % mod);
}

const int n = 242;

int a[n];

int f(int l, int r, int h){
	if(r-l == 0) return 0;
	pii mx = {a[l], l};
	for(int i = l; i < r; i++) mx = max(mx, {a[i], i});
	return f(l, mx.ss, mx.ff) + f(mx.ss+1, r, mx.ff) + (mx.ff < h);
}

void init(){
	for(int i = 0; i < n; i++){
        a[i] = 0;
        int x = i+1;
        while(x % 3 == 0) x/=3, a[i]++;
    }
}

signed main(){
    init();
	// while(a[0] != m+1){
	// 	// for(int i = 0; i < n; i++)cout << a[i] << ' ';
	// 	// cout << '\n';
	// 	int x = f(0, n, m+2);
	// 	ans += x;
	// 	// cout << x << '\n';
	// 	ans %= mod;
	// 	a[n-1]++;
	// 	for(int i = n-1; i > 0; i--) {
	// 		if(a[i] == m+1) a[i] = 1, a[i-1]++;
	// 		else break;
	// 	}
	// }
	// cout << endl;
    int mxa = a[0];
    for(int i = 0; i < n; i++)mxa = max(mxa, a[i]);
	ll m = f(0, n, mxa+1);
	dbg(m);
    ll mm = m * m % mod;
    mm = mm * mm % mod;
	dbg(mm);
}

/*
3
3 2
3 1 2 0
3
3 1
3 2 1 0
*/