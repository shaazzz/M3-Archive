#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Mod = 229939;
const int N = 200;

int n;
ll dp[10][N][N];
int a[3];

bool Check(int,int,int,int,int);
int M1(int,int,int,int,int);
int M2(int,int,int,int,int);

int main(){
	n = 7;
	dp[0][0][0] = 1;
	
	for(int x = 1;x <= n;x++)
		for(int mask1 = 0;mask1 < (1<<n);mask1++){
			for(int mask2 = 0;mask2 < (1<<n);mask2++)
				for(int i = 1;i <= n;i++)
					for(int j = i+1;j <= n;j++)
						for(int k = j+1;k <= n;k++){
							if(Check(mask1, mask2, i, j, k)){
								dp[x][mask1][mask2] += dp[x-1][M1(mask1, mask2, i, j, k)][M2(mask1, mask2, i, j, k)];
								dp[x][mask1][mask2] %= Mod;
								}
						}
		}	
	cout << dp[7][127][127] << endl;
}

bool Check(int mask1,int mask2,int i,int j,int k){
	a[0] = i-1, a[1] = j-1, a[2] = k-1;
	for(int x = 0;x < 3;x++)
		if(!((mask1 >> a[x]) & 1) and !((mask2 >> a[x]) & 1))	
			return false;
	return true;
}

int M1(int mask1, int mask2, int i, int j, int k){
	a[0] = i-1, a[1] = j-1, a[2] = k-1;
	for(int x = 0;x < 3;x++)
		if(((mask1 >> a[x]) & 1))
			mask1 -= (1<<a[x]);
		else
			mask1 += (1<<a[x]);
	return mask1;
}

int M2(int mask1, int mask2, int i, int j, int k){
	a[0] = i-1, a[1] = j-1, a[2] = k-1;
	for(int x = 0;x < 3;x++)
		if(!((mask1 >> a[x]) & 1))
			mask2 -= (1<<a[x]);
	return mask2;
}
