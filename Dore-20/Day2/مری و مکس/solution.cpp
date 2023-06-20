#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll , ll> pll;

const ll maxn = 1389005 , md = 97987 , inf = 2e16;

string s;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ifstream fin("C:\\Users\\S2\\Desktop\\20_presummer_exam2_marysub.txt");
	ll ans = 0 , cnt = 0;
	for(ll i = 1 ; i <= 4817 ; i++){
		getline(fin , s);
		ll sz = s.size();
		for(ll i = 2 ; i < sz ; i++){
			if(s[i - 2] == s[i - 1] && s[i - 1] == '-' && s[i] == '>'){
				ll h1 = 0 , h2 = 0;

				h1 += (s[0] - '0') * 36000000;
				h1 += (s[1] - '0') * 3600000;
				h1 += (s[3] - '0') * 600000;
				h1 += (s[4] - '0') * 60000;
				h1 += (s[6] - '0') * 10000;
				h1 += (s[7] - '0') * 1000;
				h1 += (s[9] - '0') * 100;
				h1 += (s[10] - '0') * 10;
				h1 += (s[11] - '0') * 1;

				h2 += (s[17 + 0] - '0') * 36000000;
				h2 += (s[17 + 1] - '0') * 3600000;
				h2 += (s[17 + 3] - '0') * 600000;
				h2 += (s[17 + 4] - '0') * 60000;
				h2 += (s[17 + 6] - '0') * 10000;
				h2 += (s[17 + 7] - '0') * 1000;
				h2 += (s[17 + 9] - '0') * 100;
				h2 += (s[17 + 10] - '0') * 10;
				h2 += (s[17 + 11] - '0') * 1;

				ans += h2 - h1 + 1;
			}
		}
	}
	ans %= md;
	cout<<ans<<'\n';
	return 0;
}