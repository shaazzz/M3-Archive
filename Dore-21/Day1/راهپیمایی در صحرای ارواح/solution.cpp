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

int dx[4] = {1, 1, -1, -1}, dy[4] = {1, -1, -1, 1};

int main(){ IOS();
     ll s = ll(2e9); 
     for(int a = 2; ; a += 2){
          if(s > 8*a - 4){
               s -= 8*a - 4;
          } else{
               pp cr = {-a + 2, 0};
               int rem = a-1, pos = 0;
               while(s){
                    if(!rem){
                         pos++;
                         if(pos == 1) rem = a-1;
                         else rem = a;
                    }
                    rem--;
                    cr.ss += dy[pos];
                    s--;
                    if(!s) break;
                    cr.ff += dx[pos];
                    s--;
               }
               cout << abs(1ll*cr.ff*cr.ss)%delta << '\n';
               return 0;
          }
     }     
     return 0;
}