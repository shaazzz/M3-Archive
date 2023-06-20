#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Mod = 229939;
const ll N = 1e4 + 10;

ll n, X, Y;
ll fact[N], inv[N];
ll T[4][N];

void Fact();
ll Tavan(ll,ll);
ll Sigma_y(int);

int main(){
	Fact();
	for(int i = 0;i < N;i++)
		T[2][i] = Tavan(2, i), T[3][i] = Tavan(3, i);
	
	// b
	n = (Mod * Mod) + 3;
	
	X = 3; // X = (n * (n-1) / 2) % Mod
	bool seen = false;
	int count0 = 0, count1 = 0;
	
	for(ll i = 0, j = 1;j*2LL <= n;i++, j *= 2LL)
		Y += (3 * Sigma_y(i)), Y %= Mod;
		
	for(int i = 40;i >= 0;i--)
		if((n >> i) & 1){
			if(seen){
				count0++;
				Y += ((Sigma_y(i) * T[2][count0]) % Mod * T[3][count1]) % Mod;
				count0--;
			}
			count1++;
			seen = true;			
		}else if(seen){
			count0++;
		}
		
	cout << (X * Y) % Mod << endl;;
	
	// c
	ll m = 10000;	
	Y = 0, X = (T[2][m] * (T[2][m] - 1) / 2) % Mod;
	for(int i = 0;i <= m-1;i++){
		Y += Sigma_y(i) * 3LL, Y %= Mod;
	}
	cout << X * Y % Mod << endl;
}

ll Tavan(ll a, ll b){
	if(!b)
		return 1;
	ll c = Tavan(a, b/2); c = (c*c) % Mod;
	if(b & 1)
		return (c * a) % Mod;
	return c;
}

void Fact(){
	fact[0] = 1, inv[0] = 1;
	for(int i = 1;i < N;i++)
		fact[i] = (fact[i-1] * i) % Mod, inv[i] = Tavan(fact[i], Mod-2);	
}

ll C(int x,int y){ 
	return fact[y] * inv[x] % Mod * inv[y-x] % Mod;
}

ll Sigma_y(int y){ //
	ll S = 0;
	for(int i = 0;i <= y;i++)
		S += (C(i, y) * (T[2][i] * T[3][y-i] % Mod)) % Mod;
	return S % Mod;
}

