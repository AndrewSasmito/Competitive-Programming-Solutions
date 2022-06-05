#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long
typedef pair<ll, ll> pi;
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;


vector <pair<ll, ll>> s;
vector <pair<ll, ll>> v;
int n, q;
ll x, y;

bool check(ll x, ll y){
    int pos = upper_bound(v.begin(), v.end(), pi{x, 2e9}) - v.begin() - 1;
    
    if (pos >= 0 && v[pos].second >= y){
        return 1;
    }else{
        return 0;
    }
}

void solve(){
	cin >> n >> q;

	for (int i = 0; i<n; ++i){
		cin >> x >> y;

		s.push_back({x, y});
	}
	sort(s.begin(), s.end());
	

	/* DEBUG
	cout << "LIST:\n";
	for (int i = 0; i<v.size(); ++i){
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
	cout << '\n';
	*/

    v.push_back(s[0]);
	
	int j;
	for (j = 1; j<n; ++j){
		if (v.back().second + 1 >= s[j].first){
			v.back().second = max(v.back().second, s[j].second);
		}else{
	    	v.push_back({s[j].first, s[j].second});
		}
	}

	
	/*DEBUG
	cout << "LIST:\n";
	for (int i = 0; i<v.size(); ++i){
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
	cout << '\n';
	*/

	for (int i =0; i<q; ++i){
		cin >> x >> y;

		cout << (check(x, y) == 1 ? 'Y' : 'N') << '\n';
		
	}


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

	//cout << elapsedTime << '\n';
}
