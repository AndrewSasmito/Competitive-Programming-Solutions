#include <bits/stdc++.h>
using namespace std;

int cur = 1, ans = 0;
string s;
char c;
int main(){
	cin >> s;

	c = s[0];
	for (int i = 1; i<s.size(); ++i){
		if (c == s[i]){
			++cur;
		}else{
			c = s[i];
			ans = max(ans, cur);
			cur = 1;
		}
	}
	ans = max(ans, cur);
	cout << ans << '\n';
}
