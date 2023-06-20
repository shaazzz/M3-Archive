#include<bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

const int Mod = 229939;

ll n,ans;
int b[5];
vector <vector<int> > a;
int cnt;

bool Make(int,int);
ll Cnt(int,int);

int main(){
	for(int i = 1;i <= 15;i++)
		for(int i2 = i+1;i2 <= 15;i2++)
			for(int i3 = i2+1;i3 <= 15;i3++)
				for(int i4 = i3+1;i4 <= 15;i4++)
					for(int i5 = i4+1;i5 <= 15;i5++){
						vector <int> vec;
						vec.pb(i-1), vec.pb(i2-2), vec.pb(i3-3), vec.pb(i4-4), vec.pb(i5-5);
						a.pb(vec);
					}
	//cout << "end1" << endl;
	
	for(int i = 0;i < a.size();i++) // satr
		for(int j = 0;j < a.size();j++){ // soton
			if(Make(i, j)){
				ans += Cnt(i, j);
				ans %= Mod;
			}
		}
	cout << ans % Mod << endl;
}

bool Make(int x,int y){
	int mx1 = 0, mx2 = 0;
	for(int i = 0;i < 5;i++)
		mx1 = max(mx1, a[x][i]), mx2 = max(mx2, a[y][i]);
	if(mx1 < 2 or mx2 < 2)
		return false;
	
	
	for(int i = 0;i < 5;i++)
		b[i] = a[y][i];
	for(int i = 4;0 <= i;i--){
		sort(b, b+5);
		int s = a[x][i];
		set<pair<int, int>> ss;
		for(int j = 0; j < 5; j++){
			if(b[j]) ss.insert({b[j], j});
		}
		vector<int> us(5);
		while(ss.size() && s){
			auto it = prev(end(ss));
			auto[vl, id] = *it;
			ss.erase(it);
			us[id]++;
			b[id]--;
			s--;
			if(us[id] < 2 && b[id]){
				ss.insert({b[id], id});
			}
		}
		if(s)
			return false;
	}
	for(int i = 0;i < 5;i++)
		if(b[i])
			return false;
		
	return true;
}

ll Cnt(int x,int y){
	ll c = 1, f1 = 120, f2 = 120;
	for(int i = 1;i < 5;i++){
		if(a[x][i] != a[x][i-1])
			c = 1;
		else
			c++;
		f1 /= c;
	}
	
	c = 1;
	for(int i = 1;i < 5;i++){
		if(a[y][i] != a[y][i-1])
			c = 1;
		else
			c++;
		f2 /= c;
	}
	
	return f1*f2;
}



