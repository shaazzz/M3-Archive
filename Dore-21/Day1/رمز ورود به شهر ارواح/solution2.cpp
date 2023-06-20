#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES": "NO")
#define all(x) x.begin(),x.end()
#define ll long long
#define pii pair<int,int>
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

const ll delta = 29123;

int process(long long x) {
    int y = 0;
    if (x % 2) return -1;
    for (x = x / 2; x > 1; x = x / 2) {
        int b = (x + 1) % 2;
        int k = 0;
        for (int i = y + 2; i > 2; i--)
            k++;
        y += k;
        y += b;
    }
    return y;
}

int my_process(long long x) {
    int y = 0;
    if (x % 2) return -1;
    for (x = x / 2; x > 1; x = x / 2) {
        int b = (x + 1) % 2;
        int k = y;
        y += k;
        y += b;
    }
    return y;
}

int main()
{
    int test = 0b110010100011011011101010001001;
    ll ans = 0b10110111010100010010011101011000LL;
    if (test == delta * delta)
        cout << "GOOD1\n";
    if(my_process(ans) == delta*delta)
        cout << "GOOD2\n";
    if(process(ans) == delta*delta)
        cout << "GOOD3\n";
    /*ll ans;
    for (ll i = 0;; i += 2)
    {
        ans = my_process(i);
        if (ans == delta * delta)
        {
            ans = i;
            break;
        }
    }*/
    //cout << ans << '\n';
    //cout << process(ans) << '\n';
    //cout << delta * delta << '\n';
    //printf("%x\n", delta * delta);
    cout << ans << '\n';
}
