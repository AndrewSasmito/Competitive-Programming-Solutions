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
	int n, k, ans = 0, score;
	cin>>n>>k;


	for (int i = 0; i<k; i++){
		int x;
		cin>>x;

		if (x == 0){
			ans = i;
			break;
		}
		else if (i == k-1){
			score = x;
			ans += k;
		}
	}
	if (ans==k){
		for (int i = k; i<n; i ++){
			int j;
			cin>>j;
			if (j == score){
				ans+= 1;
			}
			else{
				break;
			}
		}
		cout<<ans;
	}
	else{
		cout<<ans;
	}
}
