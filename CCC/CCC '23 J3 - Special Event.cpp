#include <bits/stdc++.h>
using namespace std;

int n, d[6], mx = 0;
bool f = 0;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i<n; ++i){
		cin >> s;
		for (int i = 0; i<5; ++i){
			if (s[i] == 'Y'){
				++d[i];
			}
		}
	}

	for (int i = 0; i<5; ++i){
		mx = max(mx, d[i]);
	}

	for (int i = 0; i<5; ++i){
		if (mx == d[i]){
			if (f == 0){
				cout << i + 1;
			}else{
				cout << ',' << i + 1;
			}

			f = 1;
		}
	}
	cout << '\n';
}
