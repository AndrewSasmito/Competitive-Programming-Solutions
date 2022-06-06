#include <iostream>
#include <algorithm>
using namespace std;
 
#define ll long long
int main()
{
 
	ll n;
	cin>>n;
	
 
	if (n%2 == 0){
		int x;
		x = n/2;
 
			if (x%2 ==0 or x>=2){
				cout<<"YES";
 
			}
			
			else{
				cout<<"NO";
			}
	}
	
	else{
		cout<<"NO";
	}
	
}
