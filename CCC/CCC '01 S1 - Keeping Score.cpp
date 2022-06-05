#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

string s;
vector <char> v[4];
int cnt[4];
void solve(){
	cin >> s;

	int cur = 0, curx = 0;
	for (int i = 0; i < s.size(); ++i){
		if (s[i] == 'C'){
			continue;
		}
		else if (s[i] == 'D'){
			cnt[cur] = curx;
			++cur;
			curx = 0;
			continue;
		}else if (s[i] == 'H'){
			cnt[cur] = curx;
			++cur;
			curx = 0;
			continue;
		}else if (s[i] == 'S'){
			cnt[cur] = curx;
			++cur;
			curx = 0;
			continue;
		}else if (s[i] == 'A'){
			curx += 4;
		}else if (s[i] == 'K'){
			curx += 3;
		}else if (s[i] == 'Q'){
			curx += 2;
		}else if (s[i] == 'J'){
			curx += 1;
		}
		v[cur].push_back(s[i]);
	}
	cnt[cur] = curx;
	curx = 0;


	cout << "Cards Dealt Points\n";

	cout << "Clubs";
	for (char c : v[0])
		cout << ' ' << c;
	if (v[0].size() == 2){
		cnt[0] += 1;
	}
	else if (v[0].size() == 1){
		cnt[0] += 2;
	}
	else if (v[0].size() == 0){
		cnt[0] += 3;
	}
	curx += cnt[0];
	cout << ' ' << cnt[0] << '\n';

	cout << "Diamonds";
	for (char c : v[1])
		cout << ' ' << c;
	if (v[1].size() == 2){
		cnt[1] += 1;
	}
	else if (v[1].size() == 1){
		cnt[1] += 2;
	}
	else if (v[1].size() == 0){
		cnt[1] += 3;
	}
	curx += cnt[1];
	cout << ' ' << cnt[1] << '\n';

	cout << "Hearts";
	for (char c : v[2])
		cout << ' ' << c;
	if (v[2].size() == 2){
		cnt[2] += 1;
	}
	else if (v[2].size() == 1){
		cnt[2] += 2;
	}
	else if (v[2].size() == 0){
		cnt[2] += 3;
	}
	curx += cnt[2];
	cout << ' ' << cnt[2] << '\n';

	cout << "Spades";
	for (char c : v[3])
		cout << ' ' << c;
	if (v[3].size() == 2){
		cnt[3] += 1;
	}
	else if (v[3].size() == 1){
		cnt[3] += 2;
	}
	else if (v[3].size() == 0){
		cnt[3] += 3;
	}
	curx += cnt[3];
	cout << ' ' << cnt[3] << '\n';


	cout << "Total " << curx << '\n';


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
