#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int N = 3e5+10,delta = 229939;
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%delta;
        a = 1ll*a*a%delta;
        k >>= 1;
    } 
    return z; 
}

int num_div[N];
int calc[N];

int main(){
	for (int i = 1; i < delta; i++){
		for (int j = i; j < delta; j += i){
			num_div[j]++;
		}
	}
	int mx = delta-1;
	ll ans = 0;
	for (int i = mx; i >= 1; i--){
		calc[i] = poww(mx/i,2);
		for (int j = 2*i; j < delta; j += i) calc[i] -= calc[j];
		if (num_div[i] == 48) ans += calc[i];
		if (ans >= delta) assert(0);
	}
	cout << poww(ans,ans) << endl;
	return 0;
}

