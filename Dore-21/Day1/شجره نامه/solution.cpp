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

const ll mod = 1e9 + 7, delta = 29123, maxn = 1e5 + 5, maxk = 100 + 5, lg = 21, inf = ll(1e18) + 5;

int dist(int a, int b){
     int res = 0;
     while(a - b){
          if(a < b) swap(a, b);
          a >>= 1;
          res++;
     } 
     return res;
}

bool vis[maxn];

int main(){ IOS();
     vector<int> prm;
     rep(i,2,maxn){
          if(!vis[i]){
               if(i <= delta) prm.pb(i);
               for(int j = 2*i; j < maxn; j += i){
                    vis[j] = true;
               }
          }
     }     
     ll ans = 1;
     rep(i,0,sz(prm)){
          rep(j,i+1,sz(prm)){
               if(!vis[prm[i] + prm[j] + 1]){
                    ans = ans*dist(prm[i], prm[j])%delta;
               }
          }
     }
     cout << ans << '\n';
     return 0;
}