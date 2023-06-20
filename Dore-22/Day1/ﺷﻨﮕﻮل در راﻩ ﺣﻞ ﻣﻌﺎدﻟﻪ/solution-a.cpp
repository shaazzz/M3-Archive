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
	set<int>s;
    for(int a=1;a<=10;++a){
        for(int b=1;b<=10;++b){
            for(int c=1;c<=10;++c){
                for(int d=1;d<=10;++d){
                    int m=__gcd((a|b), c)^d;
                    s.insert(m);
                }
            }
        }
    }
    cout<<tav(s.size(), 9)<<'\n';
}