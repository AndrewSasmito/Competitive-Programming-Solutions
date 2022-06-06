#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string.h>
#include <string>
using namespace std;

#define ll long long
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, m, a, amount;

	cin>>n>>m>>a;
	

	if (n%a == 0){
		amount = n/a;
	}
	else if (a>n){
		amount = 1;
	}
	else{
		amount = (n/a)+1;
	}

	if (m%a == 0){
		amount *= m/a;
	}
	else if(a>m){
		amount *= 1;
	}
	else{
		amount *= (m/a)+1;
	}

	cout<<amount;
}
