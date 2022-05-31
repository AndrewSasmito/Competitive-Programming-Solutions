#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

void solve(){
    string s, t, fs = "", ts = "";
    getline(cin, s);
    getline(cin, t);

	for (int i = 0; i<s.size(); ++i){
		if (s[i] != ' ')
			fs+=s[i];
	}
	for (int i = 0; i<t.size(); ++i){
		if (t[i] != ' ')
			ts+=t[i];
	}
	
	int high = max(ts.size(), fs.size());
	int low = min(ts.size(), fs.size());

	sort(ts.begin(), ts.end());
	sort(fs.begin(), fs.end());

	int first = 0, second = 0, cnt = 0;
	for (int i = 0; i<high; ++i){
		if (fs[i + first] != ts[i+second]){
			if (high = ts.size())
				++second;
			else
				++first;
		}else
			++cnt;
	}
	cout<<(cnt == low?"Is an anagram.":"Is not an anagram.")<<'\n';
}

 
 
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int testcases = 1;
	//cin >> testcases;
	for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){ 
	

	// Normal
	solve();
	//Google
	//cout<<"Case #"<<number_of_total_test_cases<<": "<<google_answer;
	}
}
