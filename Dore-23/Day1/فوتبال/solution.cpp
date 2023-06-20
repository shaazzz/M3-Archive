#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast,unroll-loops")
// #pragma GCC target ("avx2")
#define rep(i,l,r) for(int i = (l); i < (r); i++)
#define per(i,r,l) for(int i = (r); i >= (l); i--)
#define all(x) begin(x), end(x)
#define sz(x) (int)size(x)
#define pb push_back
#define ff first
#define ss second
typedef long long ll;
typedef pair<ll, ll> pp;

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

const ll mod = 1e9 + 7, delta = 229939, maxn = 1e4 + 5, lg = 21, inf = ll(1e18) + 5;

ll pw(ll a, ll b, ll md){
     if(!b) return 1;
     ll k = pw(a, b>>1, md);
     return k*k%md*(b&1?a:1ll)%md;
}

ll C[maxn][maxn], p2[maxn], p3[maxn];

ll slvAB(ll a){
     ll len = 0;
     ll k = a;
     vector<bool> v;
     while(k) {
          v.pb(k&1ll);
          len++, k >>= 1ll;
     }
     ll ans = 0;
     rep(i,1,len){
          rep(j,0,i){
               ans += C[i-1][j]*p3[j+1]%delta*p2[i-1-j]%delta;
               ans %= delta;
          }
     }
     reverse(all(v));
     ll c[2] = {0, 1};
     rep(i,1,sz(v)){
          if(v[i]){
               c[0]++;
               int rem = len - i - 1;
               rep(k,0,rem + 1){
                    ans += C[rem][k]*p3[c[1] + k]%delta*p2[c[0] + rem - k]%delta;
                    ans %= delta;
               }
               c[0]--;
          }
          c[v[i]]++;
     }
     if(a&1ll) ans = ans*a%delta*(a/2)%delta;
     else ans = ans*(a/2)%delta*(a-1)%delta;
     return ans;
}

ll slvC(ll n){
     ll ans = 0;
     rep(i,1,n+1){
          rep(j,0,i){
               ans += C[i-1][j]*p3[j+1]%delta*p2[i-j-1]%delta;
               ans %= delta;
          }
     }
     return ans*pw(2, n-1, delta)%delta*(pw(2, n, delta) - 1)%delta;
}

int main(){ IOS();
     rep(i,0,maxn){
          C[i][0] = 1;
          rep(j,1,i+1){
               C[i][j] = C[i-1][j] + C[i-1][j-1];
               if(C[i][j] >= delta) C[i][j] -= delta;
          }
          p2[i] = pw(2, i, delta), p3[i] = pw(3, i, delta);
     }
     cout << slvAB(delta*delta + 3) << '\n';
     return 0;
}