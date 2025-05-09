#include <bits/stdc++.h>
#define dbg(x) cout << #x << ": " << x << '\n';

using namespace std;

typedef long long ll;

const int mod = 10847;

/*
* 	answer if numbers where 0, 1, ... 2^n-1
*/

const int maxN = 14;

int choose[maxN+1][maxN+1];

int f(int n){
	if(n <= 2) return 0;
	int r = f(n-1)*2 % mod; // inversions between numbers with the first bit = 0 + inversions between numbers with the first bit = 1
	int c[n+1]; // c[i] = number of integers with popcount = i
	int pfc[n+1]; // c[i] = number of integers with popcount <= i
	for(int i = 0; i < n; i++){
        c[i] = choose[i][n-1];
		pfc[i] = (c[i] + (i > 0 ? pfc[i-1] : 0)) % mod;
	}
	for(int i = 2; i < n; i++){
        // inversions between numbers with the first bit = 0 and popcount = i, and numbers with the first bit = 1 (popcount must be <= i-2 excluding the first bit)
		r += 1ll * c[i] * pfc[i-2] % mod;
		r %= mod;
	}
	return r;
}

signed main(){
	for(int i = 0; i <= maxN; i++){
		for(int j = 0; j <= i; j++){
			if(j == 0 || i == j) {
				choose[j][i] = 1;
			}
			else{
				choose[j][i] = (choose[j-1][i-1] + choose[j][i-1]) % mod;
			}
		}
	}
	int m = f(maxN);
	dbg(m);
	int mm = 1;
	for(int i = 1; i <= maxN; i++){
		mm = 1ll * mm * m % mod;
	}
	dbg(mm);
}