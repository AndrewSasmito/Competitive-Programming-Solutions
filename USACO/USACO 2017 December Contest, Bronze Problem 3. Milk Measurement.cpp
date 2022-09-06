#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedtime ((double)(clock()-__init_time__)/clocks_per_sec)<<" seconds"
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

//custom hash for hash map
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t fixed_random = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + fixed_random);
    }

	/*
	 	* How To Use:
	 	*
	 	* unordered_map<long long, int, custom_hash> safe_map;
	 	* gp_hash_table<long long, int, custom_hash> safe_hash_table;
	 	*
	 */
};



void usaco(){

	freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);

	/*
		 * How To Use:
		 *
		 * Call usaco() to take input and output
		 * to & from a textfile
		 *
		 * freopen("File Name", "r" or "w", stdin or stdout);
		 *
		 * r && stdin == read
		 *
		 * w && stdout == print
		 *
	 */
}

int n, q, num, ans = 0, cur = 7;
unordered_map <string, int> m;
vector <pair<int, pair<string, int>>> v;
string t, r;
//Took over an hour to solve because I didn't know that there were only 3 cows and my more complex solution failed :(
void solve(){
	usaco();
	cin >> n;

	m["Bessie"] = 7, m["Mildred"] = 7, m["Elsie"] = 7;


	for (int i = 0; i<n; ++i){
		cin >> q >> t >> r;

		
		if (r[0]  == '+'){
			r = r.substr(1);
			num = stoi(r);
			v.push_back({q, {t, num}});
		}else{
			r = r.substr(1);
			num = stoi(r);
			v.push_back({q, {t, num * -1}});
		}
	}
	
	sort(v.begin(), v.end());
	
	bool bf = 1, mf = 1, ef = 1, bs, ms, es;

	for (int i = 0; i<v.size(); ++i){
		//cout << v[i].first << ' ' << v[i].second.first << ' ' << v[i].second.second << '\n';
		t = v[i].second.first;
		q = v[i].second.second;
		//cout << "Stats: " << t << ' ' << q << '\n';

		m[t] += q;

		num = max(m["Bessie"], max(m["Mildred"], m["Elsie"]));

		bs = (m["Bessie"] == num);
		ms = (m["Mildred"] == num);
		es = (m["Elsie"] == num);

		if (bf != bs || mf != ms || ef != es){
			++ans;
		}
		//cout << bf << ' ' << bs << ' ' << mf << ' ' << ms << ' ' << ef << ' ' << es << ' ' << cur << ' ' << num << ' ' <<  m["Bessie"] << ' ' << m["Mildred"] << ' ' << m["Elsie"] << '\n';
		bf = bs, mf = ms, ef = es, cur = num;
	}

	cout << ans << '\n';
}
//do not submit if usaco(); is open

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/

int main(){
	//Speed up
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
