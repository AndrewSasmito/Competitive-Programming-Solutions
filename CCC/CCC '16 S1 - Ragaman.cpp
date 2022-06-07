#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

string s1, s2;
int cnt = 0, ans = 0;
unordered_map<char, int> m1;
unordered_map<char, int> m2;
void solve(){
	cin >> s1 >> s2;

	for (int i = 0; i<s1.size(); ++i){

		if (s1[i] != '*'){
			++m1[s1[i]];
		}else{
			++cnt;
		}
		
		if (s2[i] != '*'){
			++m2[s2[i]];
		}else{
			++cnt;
		}
	}

	for (char c = 'a'; c<='z'; ++c){
		ans += abs(m1[c] - m2[c]);
	}
	
	cout << (ans <= cnt ? 'A' : 'N') << '\n';
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
