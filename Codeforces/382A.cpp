#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

void usaco(){
	freopen("lostcow.in", "r", stdin);
	freopen("lostcow.out", "w", stdout);
}

//do not submit if usaco(); is open

string s, t, a1, a2;
bool f = 0;
void solve(){
	cin >> s;

	for (int i = 0; i<s.size(); ++i){
		if (s[i] == '|'){
			f = 1;
		}else if (f == 0){
			a1 += s[i];
		}else{
			a2 += s[i];
		}
	}
	cin >> t;

	for (int i = 0; i<t.size(); ++i){
		if (a1.size() <= a2.size()){
			a1 += t[i];
		}else{
			a2 += t[i];
		}
	}

	if (a1.size() != a2.size()){
		cout << "Impossible\n";
	}else{
		cout << a1 << '|' << a2 << '\n';
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

	//usaco();


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
