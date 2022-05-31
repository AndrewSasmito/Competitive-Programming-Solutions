#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n, x;
void solve(){
	cin >> n;

	vector <int> v1(n + 1);
	vector <int> v2(n + 1);

	for (int i = 1; i<=n; ++i){
		cin >> x;
		v1[i] = v1[i-1] + x;
	}
	for (int i = 1; i<=n; ++i){
		cin >> x;
		v2[i] = v2[i-1] + x;
	}

	for (int i = n; i>=1; --i){
		if (v1[i] == v2[i]){
			cout << i << '\n';
			return;
		}
	}
	cout << 0 << '\n';
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
