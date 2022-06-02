#include <bits/stdc++.h>
using namespace std;

long long sum = 0, n, x;
int main(){
	cin >> n;

	for (int i = 1; i < n; ++i){
		cin >> x;
		sum += x;
	}

	cout << ((n*(n+1))/2) - sum << '\n';
}
