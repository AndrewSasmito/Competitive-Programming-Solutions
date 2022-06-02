#include <bits/stdc++.h>
using namespace std;

string ans1, s;
int x, ans2 = 300;
int main(){

	while (true){
		cin >> s >> x;

		if (x < ans2){
			ans2 = x;
			ans1 = s;
		}

		if (s == "Waterloo")
			break;
	}
	cout << ans1 << '\n';
}
