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

const ll mod = 1e9 + 7, delta = 29123, maxn = 1e6 + 5, lg = 21, inf = ll(1e18) + 5;

vector<int> prm = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

ll ans = inf, X = 2011;

map<ll, bool> mp;

void slv(ll a, vector<int> &cr){
     if(a >= ans) return;
     if(mp[a]) return;
     mp[a] = true; 
     int cnt = 1;
     for(int x: cr) cnt *= x + 1;
     if(cnt >= X) {
          ans = a;
     }
     else{
          rep(i,0,sz(cr)){
               if((!i || cr[i-1] > cr[i])){
                    cr[i]++;
                    slv(a*prm[i], cr);
                    cr[i]--;
               }
          }
     }
}

int main(){ IOS();
     ans = 1;
     for(int x: prm) ans *= x;
     vector<int> x = {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
     slv(6, x);
     cout << ans%delta << '\n';
     return 0;
}