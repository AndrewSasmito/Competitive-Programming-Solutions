#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;


void solve(){
int n, x;
int cur;
	cin>>n;
	
	cur = 1;

	stack <int> v;
	stack <int> s;
	
	for (int i = 0; i<n; ++i){
		cin>>x;
		v.push(x);
	}

	while (v.size()){
		x = v.top();
		v.pop();
		if (x < cur){
			continue;
		}
		else if (x == cur){
			++cur;
		}else if (s.size()>0){
			if (s.top() == cur){
				s.pop();
				++cur;
				while (true){
					if (s.top() == cur){
						s.pop();
						++cur;
					}else{
					    s.push(x);
						break;
					}
					
				}
			}else if (x != cur && s.top() != cur){
				s.push(x);
			}
		}
		else if (x != cur){
			s.push(x);
		} 
	}
	while (s.size()){
		x = s.top();
		s.pop();
		if (x != cur){
			cout<<"N\n";
			return;
		}else{
			++cur;
		}
	}
	cout<<"Y\n";
}
 
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int testcases = 1;
	cin >> testcases;
	for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){ 
	

	//Google
	//cout<<"Case #"<<number_of_total_test_cases<<": ";
	// Normal
	solve();
	}
}
