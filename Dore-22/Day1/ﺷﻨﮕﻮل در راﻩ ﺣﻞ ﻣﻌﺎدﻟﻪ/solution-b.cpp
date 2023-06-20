#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define all(v) v.begin(), v.end()
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef double db;
const int M=46639;
int pr[200], t;
bool p[1005], ex[1000];

int tav(int a, int b){
    int res=1;
    while(b>0){
        if(b&1)
            res=1LL*res*a%M;
        a=1LL*a*a%M;
        b>>=1;
    }
    return res;
}

void sieve(){
    memset(p, 1, sizeof(p));
    for(int i=2;i<1000;++i){
        if(p[i]){
            pr[t++]=i;
            for(int j=i+i;j<1005;j+=i)
                p[j]=0;
        }
    }
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	sieve();
    for(int a=0;a<t;++a){
        for(int b=0;b<t;++b){
            for(int c=0;c<t;++c){
                int A=pr[a], B=pr[b], C=pr[c];
                int m=__gcd((A|B), C);
                ex[m]=1;
            }
        }
    }
    int mx=0, mn=1e9;
    for(int abc=0;abc<1000;++abc){
        for(int d=0;d<t;++d){
            if(ex[abc]){
                int m=abc^pr[d];
                mn=min(mn, m);
                mx=max(mx, m);
            }
        }
    }
    cout<<(tav(mx, 2)+tav(mn, 4))%M<<'\n';
}