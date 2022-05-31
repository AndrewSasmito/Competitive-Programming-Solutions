#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

vector <int> s1;
vector <int> s2;
vector <int> hold;
void solve(){
	int n, x;
	cin>>n;
	for (int i = 0; i<n; ++i){
		cin>>x;

		hold.push_back(x);
	}
	sort(hold.begin(), hold.end());
	
	int loop = n/2;
	if (n%2 != 0){
		++loop;
	}
	for (int i = 0; i<loop; ++i){
		s1.push_back(hold[i]);
	}
	for (int i = loop; i < n; ++i){
		s2.push_back(hold[i]);
	}
	reverse(s1.begin(), s1.end());
	for (int i = 0; i<n/2; ++i){
		cout<<s1[i]<<" "<<s2[i]<<" ";
	}
	if (s1.size() > s2.size()){
		cout<<s1[loop-1];
	}
	cout<<'\n';
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
