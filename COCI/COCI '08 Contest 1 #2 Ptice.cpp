#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

vector <char> ad = {'A', 'B', 'C'};
vector <char> br = {'B', 'A', 'B', 'C'};
vector <char> gor = {'C', 'C', 'A', 'A', 'B', 'B'};
string s;
vector <pair <int, string>> v;
int s1 = 0, s2 = 0, s3 = 0, n;
void solve(){
	cin >> n >> s;

	for (int i = 0; i<n; ++i){
		if (ad[i%3] == s[i]) ++s1;
		if (br[i%4] == s[i]) ++s2;
		if (gor[i%6] == s[i]) ++s3;
	}

	int an = max(s1, max(s2, s3));

	cout << an << '\n';

	if (s1 == an){
		cout << "Adrian\n";
	}
	if (s2 == an){
		cout << "Bruno\n";
	}
	if (s3 == an){
		cout << "Goran\n";
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
