
#include<bits/stdc++.h>
using namespace std;


bool isprime(int x){
	if (x <= 1) return false;
	for (int i = 2; i * i <= x; i++){
		if (x % i == 0) return false;
	}
	return true;
}

int n = 229939 + 1;
int mod = 200012;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);

	int ans = 0;

	for (int i = 1; i <= n; i++) ans += isprime(i-1);
	
	cout << ans << '\n';
	cout << 2 * (ans-1) << '\n';
	cout << ans << '\n';
	cout << n - ans << '\n';
	cout << 1ll * n/2 * n/2 % mod << '\n';
	cout << 1 << '\n';
	return 0;
}
