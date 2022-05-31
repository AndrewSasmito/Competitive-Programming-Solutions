#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

ll h;
int t, x, m;
vector <int> v;
string s;
void solve(){
	cin >> h >> t;

	for (int i = 0; i<t; ++i){
		cin >> x;
		v.push_back(x);
	}
	cin >> m >> s;
	int max_dis = 0, cur_dis = 0;

	for (int i = 0; i<m; ++i){
		if (s[i] == '1'){
			max_dis = max(max_dis, cur_dis);
			cur_dis = 0;
		}else{
			++cur_dis;
		}
	}
	int tract;
	for (int i = 0; i<v.size(); ++i){
		if (v[i] <= max_dis)
			tract = v[i];
		else
			break;
	}
	//cout << tract << ' ' << h << '\n';
	cout << (h % tract == 0 ? h/tract : (h/tract) + 1) << '\n';
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
