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

bool comp[N];
int zarb[N];
vector<int> taj[N];

int main(){
	for (int i = 2; i < delta; i++){
		if (comp[i] == 1) continue;
		taj[i].push_back(i);
		for (int j = 2*i; j < delta; j += i){
			taj[j].push_back(i);
			comp[j] = 1;
		}
	}
	int ans = 0;
	zarb[0] = 1;
	int num = delta-1;
	for (int a = 1; a <= num; a++){
		int sz = taj[a].size();
		int cnt = (1 << sz);
		for (int mask = 1; mask < cnt; mask++){
			int bit = __builtin_ctz(mask);
			zarb[mask] = taj[a][bit]*zarb[mask^(1 << bit)];
		}
		for (int mask = 0; mask < cnt; mask++){
			if (__builtin_popcount(mask)&1) ans -= num/zarb[mask];
			else ans += num/zarb[mask];
			if (ans < 0) ans += delta;
			if (ans >= delta) ans -= delta;
		}
	}
	cout << poww(ans,4) << endl;
	return 0;
}

