#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Mod = 229939;

ll n, X, Y;

ll F(int);

int main(){
	n = Mod + 3;
	for(int i = 1;i < n;i++)
		Y += F(i), Y %= Mod;
	X = (n * (n-1) / 2) % Mod; // X = 3;
	cout << X * Y % Mod << endl;
}

ll F(int y){
	ll f = 1;
	while(y > 0){
		if(y & 1)
			f *= 3, f %= Mod;
		else
			f *= 2, f %= Mod;
		y /= 2;
	}
	return f;
}