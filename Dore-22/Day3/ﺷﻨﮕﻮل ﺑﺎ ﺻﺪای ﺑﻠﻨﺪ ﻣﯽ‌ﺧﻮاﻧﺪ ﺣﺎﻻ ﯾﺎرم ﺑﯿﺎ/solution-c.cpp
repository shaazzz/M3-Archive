#include <bits/stdc++.h>
#define debug(x) cerr << #x << " : " << x << endl
using namespace std;
typedef long long ll;
constexpr int N = 12299390,delta = 229939;
 
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
ll calc[N];

int main(){
	for (int i = 1; i < N; i++){
		for (int j = i; j < N; j += i){
			num_div[j]++;
		}
	}
	int mx = N-1;
	ll ans = 0;
	for (int i = mx; i >= 1; i--){
		if (num_div[i] < 48) continue;
		calc[i] = 1ll*(mx/i)*(mx/i);
		for (int j = 2*i; j <= mx; j += i) calc[i] -= calc[j];
		if (num_div[i] == 48)
		   	ans += calc[i];
		if (ans >= delta) ans %= delta;
	}
	cout << ans << endl;
	return 0;
}

