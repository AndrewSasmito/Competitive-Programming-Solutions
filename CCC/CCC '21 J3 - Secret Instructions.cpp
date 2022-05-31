#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

string s;
bool f = 1;
void solve(){
	while (true){
		cin>>s;
		if (s == "99999")
			return;
	
		if (s[0] == '0' && s[1] == '0'){
			if (f == 1)
				cout<<"right ";
			else
				cout<<"left ";
		}
		else if ((s[0] + s[1]) % 2 == 0){
			cout<<"right ";
			f = 1;
		}else{
			cout<<"left ";
			f = 0;
		}

		cout<<s[2]<<s[3]<<s[4]<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int testcases = 1;
	//cin >> testcases;
	for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){ 
	

	//Google
	//cout<<"Case #"<<number_of_total_test_cases<<": ";
	// Normal
	solve();
	}
}
