#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

int n, ans = 0;
char a;
vector <char> first;
void solve() {
    cin>>n;
    
    for (int i = 1; i<=n; ++i){
        cin>>a;
		first.push_back(a);
    }for (int i = 0; i<n; ++i){
        cin>>a;
        if (first[i] == a) ++ans;
    }
    
    cout<<ans<<'\n';
}


 
 
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int testcases = 1;
	//cin >> testcases;
	for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){
	    
	// Normal
	solve();
	
	//Google
	//cout<<"Case #"<<number_of_total_test_cases<<": "<<google_answer;
	}
}
