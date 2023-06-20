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

bool vis[maxn];
int dp[10];

int main(){ IOS();
     rep(i,2,delta){
          if(!vis[i]){
               for(int j = i; j < delta; j += i) vis[j] = true;
               if(i > 7){
                    int len = 0;
                    int k = i, lst;
                    while(k) {
                         lst = k; 
                         k /= 10;
                         len++;
                    }
                    dp[i%10] = max({dp[i%10], len, dp[lst] + len - 1});
               }
          }
     }
     ll ans = *max_element(dp, dp + 10);
     cout << ans*ans%delta*ans%delta << '\n';
     return 0;
}