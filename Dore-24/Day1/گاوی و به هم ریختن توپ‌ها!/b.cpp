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

const int n = 10080;

vector<int> a;

void dow(int d){
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


signed main(){
    int bf = calbf();
	dbg(bf);
}

/*
3
3 2
3 1 2 0
3
3 1
3 2 1 0
*/