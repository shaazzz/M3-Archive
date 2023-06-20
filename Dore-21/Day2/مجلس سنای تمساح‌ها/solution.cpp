#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize ("Ofast,unroll-loops")
// #pragma GCC target ("avx2")
#define rep(i,l,r) for(int i = (l); i < (r); i++)
#define per(i,r,l) for(int i = (r); i >= (l); i--)
#define all(x) begin(x), end(x)
#define sz(x) (int)size(x)
#define pb push_back
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pp;

void dbg(){
     cerr << endl;
}
template<typename H, typename... T> void dbg(H h, T... t){
     cerr << h << ", ";
     dbg(t...);
}

void IOS(){
     cin.tie(0) -> sync_with_stdio(0);
     #ifndef ONLINE_JUDGE
          freopen("inp.txt", "r", stdin);
          freopen("out.txt", "w", stdout);
          #define er(...) cerr << __LINE__ << " <" << #__VA_ARGS__ << ">: ", dbg(__VA_ARGS__)
     #else
          #define er(...) 0
     #endif
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll mod = 1e9 + 7, delta = 28813, maxn = 1e5 + 5, maxk = 100 + 5, lg = 21, inf = ll(1e18) + 5;

ll pw(ll a, ll b, ll md = mod){
     if(!b) return 1;
     ll k = pw(a, b>>1ll, md);
     return k*k%md*(b&1ll? a: 1)%md;
}

int cnt[maxn];

int main(){ IOS();
     int n = 1390;
     rep(i,1,n+1){
          int k = i;
          while(k%2 == 0) k >>= 1;
          cnt[k]++;
     }
     ll ans = 1;
     rep(i,1,n+1){
          if(cnt[i]){
               ans = ans*cnt[i]%delta;
          }
     }
     cout << ans << '\n';
     return 0;
}