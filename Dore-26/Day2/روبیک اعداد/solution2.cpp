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

const int maxn  =  1e5   + 10;
const int maxn5 =  5e5   + 10;
const int maxnt =  1.2e6 + 10;
const int maxn3 =  1e3   + 10;
const int mod   =  10007;
const ll  inf   =  1e18;

vector <int> x[3][3][4], y[3][3][2];
int n = 54, d[maxn], p[maxn];

inline void fix(int &a){
    if(a >= mod)
        a -= mod;
}

inline void reset(){
    for(int i = 1; i <= n; i++)
        p[i] = i;
}

inline int calc_val(){
    int ret = 0;
    for(int i = 1; i <= n; i++){
        ll x = (mod + i - p[i]) % mod;
        x = x * x % mod;
        x = x * x % mod;
        fix(ret += x);
    }
    return ret;
}

inline void rot(int i1, int i2){
    i1 %= 3;
    i2 %= 3;
    for(int i = 1; i < 4; i++)
        for(int j = 0; j < 3; j++)
            swap(p[x[i1][i2][i - 1][j]], p[x[i1][i2][i][j]]);
    if(i2 != 1){
        for(int i = 0; i < 2; i++)
            for(int j = 2; j >= 0; j--)
                swap(p[y[i1][i2][i][j]], p[y[i1][i2][i][j + 1]]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    x[0][0][0] = {1, 2, 3};
    x[0][0][1] = {18, 30, 42};
    x[0][0][2] = {54, 53, 52};
    x[0][0][3] = {34, 22, 10};

    y[0][0][0] = {19, 21, 45, 43};
    y[0][0][1] = {20, 33, 44, 31};

    x[0][1][0] = {4, 5, 6};
    x[0][1][1] = {17, 29, 41};
    x[0][1][2] = {51, 50, 49};
    x[0][1][3] = {35, 23, 11};

    x[0][2][0] = {7, 8, 9};
    x[0][2][1] = {16, 28, 40};
    x[0][2][2] = {48, 47, 46};
    x[0][2][3] = {36, 24, 12};

    y[0][2][0] = {15, 13, 37, 39};
    y[0][2][1] = {27, 14, 25, 38};



    x[1][0][0] = {1, 4, 7};
    x[1][0][1] = {45, 33, 21};
    x[1][0][2] = {46, 49, 52};
    x[1][0][3] = {13, 25, 37};

    y[1][0][0] = {12, 36, 34, 10};
    y[1][0][1] = {11, 24, 35, 22};

    x[1][1][0] = {2, 5, 8};
    x[1][1][1] = {44, 32, 20};
    x[1][1][2] = {47, 50, 53};
    x[1][1][3] = {14, 26, 38};

    x[1][2][0] = {3, 6, 9};
    x[1][2][1] = {43, 31, 19};
    x[1][2][2] = {48, 51, 54};
    x[1][2][3] = {15, 27, 39};

    y[1][2][0] = {16, 40, 42, 18};
    y[1][2][1] = {17, 28, 41, 30};


    x[2][0][0] = {34, 35, 36};
    x[2][0][1] = {43, 44, 45};
    x[2][0][2] = {40, 41, 42};
    x[2][0][3] = {37, 38, 39};

    y[2][0][0] = {46, 48, 54, 52};
    y[2][0][1] = {47, 51, 53, 49};

    x[2][1][0] = {22, 23, 24};
    x[2][1][1] = {31, 32, 33};
    x[2][1][2] = {28, 29, 30};
    x[2][1][3] = {25, 26, 27};

    x[2][2][0] = {10, 11, 12};
    x[2][2][1] = {19, 20, 21};
    x[2][2][2] = {16, 17, 18};
    x[2][2][3] = {13, 14, 15};

    y[2][2][0] = {1, 7, 9, 3};
    y[2][2][1] = {2, 4, 8, 6};


    for(int i = 1; i < maxn; i++) 
        for(int j = i; j < maxn; j += i)
            d[j]++;

    int k = 100;
    reset();
    int cnt[3] = {0, 0, 0};
    for(int i = 1; i <= k; i++){
        rot(0, d[i]);
        cnt[d[i] % 3]++;
    }
    cout << calc_val() << endl;

    reset();
    for(int i = 1; i <= k; i++)
        rot(d[i], 1);
    cout << calc_val() << endl;

    k = 10000;
    reset();
    for(int i = 1; i <= k; i++)
        rot(d[2 * i], d[2 * i + 1]);
    cout << calc_val() << endl;
}