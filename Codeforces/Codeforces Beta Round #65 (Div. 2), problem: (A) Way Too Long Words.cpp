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
	int n, len, ans;
	cin>>n;
	for (int i=0; i<n; i++){
		string s;
		cin>>s;
		len = s.size();

		if (len>=11){
			cout<<s[0]<<len-2<<s.back()<<"\n";
		}
		else{
			cout<<s<<"\n";
		}
	
	}
}
