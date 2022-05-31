#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define forloop(i,a,b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
typedef pair<int, int> pii;
typedef vector<int> vi;


int n, i, j, ans;
string s;
int cnt[100001];

void solve(){
	cin>>s;

	cin>>n;
    
	
    for (int i = 0; i<s.length(); ++i){
		if (i == 0){
			if (s[i] == 'G'){
				cnt[i] = 1;
			}else{
				cnt[i] = 0;
			}
		}else{
			if (s[i] == 'G'){
				cnt[i] = cnt[i-1] + 1;
			}else{
				cnt[i] = cnt[i-1];
			}
		}
    }


	while (n--){
		ans = 0;
		cin>>i>>j;
		
		cout<<(i == 0?cnt[j]:cnt[j] - cnt[i-1])<<'\n';
	}
}


 
 
 
 
 
 
 
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	


	int testcases = 1;
	//cin >> testcases;
	for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){
	    
	// Normal
	solve();
	
	//Google
	//cout<<"Case #"<<number_of_total_test_cases<<": "<<google_answer;
	}
}
