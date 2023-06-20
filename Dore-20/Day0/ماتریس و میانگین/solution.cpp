#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")

typedef long long ll;

const int maxn = 1e3 + 18 , md = 10007;

int n = 1000;
int a[2][maxn][maxn] , d[maxn][maxn];

bool ok(int i , int j){
	return (i >= 0 && i < n && j >= 0 && j < n);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			a[0][i][j] = (i + 1) * (j + 1);
			for(int k = i - 1 ; k <= i + 1 ; k++){
				for(int t = j - 1 ; t <= j + 1 ; t++){
					d[i][j] += ok(k , t);
				}
			}
		}
	}
	ll res = 0;
	bool k = 1;
	while(true){
		res++;
		if(res % 1000 == 0){
			cout<<res<<endl;
		}
		bool t = true;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				if(i > j){
					a[k][i][j] = a[k][j][i];
					continue;
				}
				int sum = 0;
				for(int q = i - 1 ; q <= i + 1 ; q++){
					for(int t = j - 1 ; t <= j + 1 ; t++){
						if(ok(q , t)) sum += a[!k][q][t];
					}
				}
				a[k][i][j] = sum / d[i][j];
				t &= (a[0][i][j] == a[1][i][j]);
			}
		}
		if(t) break;
		k = !k;
	}
	cout<<res<<'\n';
	res = res * res * res % md;
	cout<<res<<'\n';
	return 0;
}