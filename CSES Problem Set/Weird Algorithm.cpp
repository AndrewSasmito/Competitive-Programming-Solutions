#include <bits/stdc++.h>
using namespace std;
long long n;
int main(){
	cin >> n;

	while (true){
		cout << n << ' ';

		if (n == 1)
			break;
		if (n % 2 == 0){
			n/=2;
		}else{
			n *= 3;
			++n;
		}
	}
}
