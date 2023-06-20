//  ~ Be Name Khoda ~  //

#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops,Ofast")

using namespace std;

typedef long long ll;

#define pb       push_back
#define mp       make_pair
#define all(x)   x.begin(), x.end()
#define fi       first
#define se       second

const int maxn  =  1e7   + 2;
const int maxn5 =  1e6   + 10;
const int maxnt =  1.2e6 + 10;
const int maxn3 =  1e3   + 10;
const int mod   =  1e9   + 7;
const ll  inf   =  1e18;
int delta = 10429;

vector <int> av[maxn5 + 10];
int cnt[maxn5 + 10];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    ll ans = 0;

    for(int i = 1; i < delta; i++) 
        for(int j = i; j < delta; j += i)
            av[j].pb(i);
    for(int i = 1; i < delta; i++){
        reverse(all(av[i]));
        for(int j = 0; j < av[i].size(); j++){
            cnt[j] = (delta - 1) / av[i][j];
            for(int k = 0; k < j; k++) if(av[i][k] % av[i][j] == 0)
                cnt[j] -= cnt[k];
            ans += ll(cnt[j]) * ((delta - 1) / (i / av[i][j]));
        }
    }
    cout << ans % delta << endl;
}