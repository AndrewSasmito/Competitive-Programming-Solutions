#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;
 
#define ll long long
int main(){
	int n, ans = 0;
	cin>>n;
 
	for(int i = 1; i<=n; i++){
		int count = 0;
		
		int x, y, z;
		cin>>x>>y>>z;
		count = x + y + z;		
 
		if (count>=2){
			ans += 1;
		}
	}
	cout<<ans;
}
