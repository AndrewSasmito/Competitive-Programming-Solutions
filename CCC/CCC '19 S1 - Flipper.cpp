#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;


string s;
bool h = 0, v = 0;
void solve(){
	cin>>s;

	for (int i = 0; i<s.size(); ++i){
		if (s[i] == 'H')
			h = not h;
		if (s[i] == 'V')
			v = not v;
	}

	if (h == 1 && v == 0){
		cout<<"3 4\n1 2\n";
	}
	else if (h == 0 && v == 1){
		cout<<"2 1\n4 3\n";
	}
	else if (h == 0 && v == 0){
		cout<<"1 2\n3 4\n";
	}
	else if (h == 1 && v == 1){
		cout<<"4 3\n2 1\n";
	}
}

 
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int testcases = 1;
	//cin >> testcases;
	for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){ 
	

	// Normal
	solve();
	//Google
	//cout<<"Case #"<<number_of_total_test_cases<<": "<<google_answer;
	}
}
