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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int w=2*(1<<(31-__builtin_clz(M-1)))-1;
    int z=0;
    cout<<7LL*w*(8*z+1)%M<<'\n';
}