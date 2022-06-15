#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n, k;
string s, temp;
vector <string> v;
void solve(){
	cin >> n >> k;
	
	for (int i = 0; i<n; ++i){
		cin >> s;
		v.push_back(s);
	}

	s = v[0];
	int cnt = 0;
	for (int i = 1; i<n; ++i){
		temp = s + ' ' + v[i];
		++cnt;

		if (temp.size() - cnt > k){
			cout << s << '\n';
			s = v[i];
			cnt = 0;
		}else{
			s = temp;
		}
	}
	
	cout << s << '\n';
}


/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/

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

	//cout << elapsedTime << '\n';
}
