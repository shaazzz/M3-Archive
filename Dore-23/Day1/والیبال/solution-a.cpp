#include<bits/stdc++.h>
using namespace std;

set <vector<int> > st;

int main(){
	//a
	for(int i = 0;i < (1<<16);i++){
		vector <int> vec;
		for(int l = 0;l < 16;l += 4){
			int x = 0;
			for(int j = l;j < l+4;j++)
				x += (i >> j) & 1;
			vec.push_back(x);
		}
		
		for(int l = 0;l < 4;l++){
			int x = 0;
			for(int j = l;j < 16;j += 4)
				x += (i >> j) & 1;
			vec.push_back(x);
		}
		st.insert(vec);		
	}
	cout << st.size() << endl;
}