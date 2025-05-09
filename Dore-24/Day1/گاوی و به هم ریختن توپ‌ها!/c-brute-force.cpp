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

int shif(int l, int r, int xl, int xr){
    int sx = (xr + xl) * (r-l+1) % mod * re2 % mod;
    int y = 0;
    y += (l-1) * sx % mod;
    int si = (r-l+2) * (r-l+1) % mod * re2 % mod;
    y += (xl-1) * si % mod;
    return y % mod;
}

const int p = 5;
vector<int> a;

void dow(int d){
    int n = a.size();
    int b[a.size()];
    for(int i = 0; i*d < n; i++){
        int l = i*d;
        int r = l+d-1;
        for(int i = l; i <= r; i++){
            b[i] = a[l+r-i];
        }
        for(int i = l; i <= r; i++){
            a[i] = b[i];
        }
    }
}

int calbf(){
    int n = p;
    for(int i = 1; i < p; i++) n *= p;
    // 3 + 12 + 15 + 8 + 5 + 24
    a.resize(n);
    for(int i = 0; i < n; i++)a[i] = i+1;
    // cout << n << endl;
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            dow(i);
        }
    }
    int m = 0;
    for(int i = 0; i < n; i++) (m += (i+1) * a[i] % mod) %= mod;
    return m;
}

int calsh(){
    int dp[p+1][2]; // dp[i][x] = answer if n = p^i and reversed indices at the end if x
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
                    // [l, r] -> l*l + (l+1) * (l+1) .. r * r
                    // -> (l-1) * (l + (l+1) + .. r) + 1*l + 2*(l+1) .. (r-l+1)*r
                    // -> (l-1) * (l + (l+1) + .. r) + (l-1) * (1 + 2 + .. (r-l+1)) + 1*1 + 2*2 + .. (r-l+1)*(r-l+1)
                }
                // cout << '\n';
            }
        }
    }
    // for(int i = 0; i < 2; i++) cout << dp[i][0] << ' ' << dp[i][1] << '\n';
    return dp[p][1];
}


signed main(){
    int bf = calbf();
	dbg(bf);
    int sh = calsh();
	dbg(sh);
}