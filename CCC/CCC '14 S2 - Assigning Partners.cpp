#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define forloop(i,a,b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
typedef pair<int, int> pii;
typedef vector<int> vi;

unordered_map <string, int> first;
unordered_map <int, string> second;
unordered_map <string, string> ans;
void solve(){

	int n; cin>>n;
	string s;
	for (int i = 1; i<=n; ++i){
		cin>>s;
		first[s] = i;
		second[i] = s;
	}for (int i = 1; i<=n; ++i){
		cin>>s;
		ans[s] = second[i];
		ans[second[i]] = s;
		if (first[s] == i || first[s] == 0){
			cout<<"bad\n";
			return;
		}
	}

	for (int i = 1; i<=n; ++i){
		if (ans[ans[second[i]]] != second[i]){
			cout<<"bad\n";
			return;
		}
	}
	cout<<"good\n";

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
