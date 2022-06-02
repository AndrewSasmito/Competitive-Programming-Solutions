#include <bits/stdc++.h>
using namespace std;

long long ans = 0, n, x, cur;
int main(){
	cin >> n >> cur;

	for (int i = 1; i < n; ++i){
		cin >> x;
	
		if (cur > x){
			ans += cur - x;
		}else{
			cur = x;
		}
	}
	cout << ans << '\n';
}
