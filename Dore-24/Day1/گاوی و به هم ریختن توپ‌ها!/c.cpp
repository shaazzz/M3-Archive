#include <bits/stdc++.h>
#define ff first
#define ss second
#define dbg(x) cout << #x << ": " << x << '\n';
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int mod = 26003;

ll po(ll b, ll p){
	return (p == 0 ? 1 : po(b*b%mod, p/2) * (p & 1 > 0 ? b : 1) % mod);
}

/*

*/

int re2;

/*
*   let f(l, r, xl, xr) = sum i * a_(i-l) for i in range [l, r] and a_(i-l) in range [xl, xr]
*   Then shif(l, r, xl, xr) calculates f(l, r, xl, xr) - f(1, r-l+1, 1, xr-xl+1)
*/
int shif(int l, int r, int xl, int xr){ 
    int sx = (xr + xl) * (r-l+1) % mod * re2 % mod;
    int y = 0;
    y += (l-1) * sx % mod;
    int si = (r-l+2) * (r-l+1) % mod * re2 % mod;
    y += (xl-1) * si % mod;
    return y % mod;
}

const int p = 13099;

int calsh(){
    int dp[p+1][2]; // dp[i][x] = answer if n = p^i (reverse indices at the end if x is true)
    int w[p+1];
    re2 = po(2, mod-2);
    for(int i = 0; i <= p; i++){
        w[i] = po(p, i);
        for(int x = 0; x <= 1; x++){
            if(i == 0) dp[i][x] = 1;
            else {
                dp[i][x] = 0;
                // cout << i << ' ' << x << " : ";
                for(int j = 0; j < p; j++){
                    int l = j * w[i-1] + 1;
                    int r = l + w[i-1] - 1;
                    int xl = l, xr = r;
                    if(x){
                        int jj = p-j-1;
                        l = jj * w[i-1] + 1;
                        r = l + w[i-1] - 1;
                    }
                    l %= mod;
                    r %= mod;
                    xl %= mod;
                    xr %= mod;
                    int qi = dp[i-1][x^1] + shif(l, r, xl, xr);
                    // cout << qi << "|";
                    dp[i][x] += qi;
                    dp[i][x] %= mod;
                    // l*xl + (l+1) * (xl+1) ... r * xr
                    // = (l-1) * (xl + (xl+1) + ... xr) + 1 * xl + 2 * (xl+1) ... (r-l+1) * xr
                    // = (l-1) * (xl + (xl+1) + ... xr) + (l-1) * (1 + 2 + .l. (r-l+1)) + (1*1 + 2*2 + ... (r-l+1)*(r-l+1))
                    // = shif(l, r, xl, xr) + (1*1 + 2*2 + ... (r-l+1)*(r-l+1))
                }
                // cout << '\n';
            }
        }
    }
    // for(int i = 0; i < 2; i++) cout << dp[i][0] << ' ' << dp[i][1] << '\n';
    return dp[p][1];
}


signed main(){
    // int l = 4, r = 7;
    // int x = 0, y = 0;
    // vector<int> pp = {4, 2, 3, 1};
    // for(int i = l; i <= r; i++) x += i * (pp[i-l]+12);
    // for(int i = 1; i <= r-l+1; i++) y += i * pp[i-1];
    // // y += (l-1) * (l+r) * (r-l+1)/2;
    // // y += (l-1) * (r-l+2) * (r-l+1)/2;
    // y += shif(l, r, 13, 16);
    // cout << x << ' ' << y << '\n';
    // return 0;
    // int bf = calbf();
	// dbg(bf);
    int sh = calsh();
	dbg(sh);
	// ll mm = m * m % mod;
	// mm = mm * mm % mod;
	// dbg(mm);
}

/*
3
3 2
3 1 2 0
3
3 1
3 2 1 0
*/