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
	
	int num;
	cin>>num;

	while (num--){
		ll n = 0, k = 0, ans = 0;
		cin>>n>>k;
		while(n!=0){
			if (n%k == 0){
				n/=k;
				ans += 1;
			}
			else{
				ll rem = 0;
				rem = n%k;
				n-=rem;
				ans+= rem;
			}
		}
		cout<<ans<<"\n";
	}	
}
