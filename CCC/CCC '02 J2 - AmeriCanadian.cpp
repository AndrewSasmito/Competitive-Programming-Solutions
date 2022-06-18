#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

string s, ans;
bool f;
vector <char> v {'a', 'i', 'o', 'u', 'e', 'y'};
void solve(){
	while (true){
		cin >> s;

		if (s == "quit!"){
			break;
		}else if (s.size() < 4){
			cout << s << '\n';
			continue;
		}

		ans = "";

		f = 1;

		for (int i = 0; i<v.size(); ++i){
			if (v[i] == s[s.size() - 3]){
				f = 0;
				break;
			}
		}
		
		if (f == 1 && s[s.size() - 2] == 'o' && s[s.size() - 1] == 'r'){
			for (int i = 0; i<s.size() - 2; ++i){
				cout << s[i];
			}
			cout << "our" << '\n';
		}else{
			cout << s << '\n';
		}
	}
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
