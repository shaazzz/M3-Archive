//  ~ Be Name Khoda ~  //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb       push_back
#define mp       make_pair
#define all(x)   x.begin(), x.end()
#define fi       first
#define se       second

const int maxn  =  1e6   + 10;
const int maxn5 =  3e3   + 10;
const int maxnt =  1.2e6 + 10;
const int maxn3 =  6e3   + 10;
const int mod   =  10067;
const ll  inf   =  1e18;


int ent[maxn3][maxn3], dp[maxn5][maxn5];
int vajh3[maxn5][2], ps[maxn5][maxn5];

inline void fix(int &a){
	if(a >= mod)
		a -= mod;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n = 3000;

    ent[0][0] = 1;
    for(int i = 1; i <= 2 * n + 6; i++){
    	ent[i][0] = 1;
    	for(int j = 1; j <= i; j++)
    		fix(ent[i][j] = ent[i - 1][j] + ent[i - 1][j - 1]);
    }

    for(int i = 1; i <= n; i++)
    	dp[i][0] = 1;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)
    	dp[i][j] = ent[i + j - 1][j];

    for(int i = 0; i <= n; i++){
    	ps[i][0] = dp[i][0];
    	for(int j = 1; j <= n; j++)
    		fix(ps[i][j] = ps[i][j - 1] + dp[i][j]);
    }

    vajh3[0][0] = 1;
    vajh3[0][1] = n;

    for(int i = 1; i <= n; i++) for(int l = 1; l <= n; l++){
		fix(vajh3[i][0] += ll(dp[i][l - 1]) * ps[i][n - l] % mod);
		fix(vajh3[i][1] += ll(dp[i][l - 1]) * ps[i + 1][n - l] % mod);
    }

    int ans = 0;
    for(int l = 1; l <= 2 * n; l++) for(int r = l; r <= 2 * n; r++)
    	fix(ans += ll(vajh3[(l - 1) / 2][(l - 1) % 2]) * vajh3[(2 * n - r) / 2][(2 * n - r) % 2] % mod);
    ans = ans * 2LL % mod;
    cout << ans << endl;
}