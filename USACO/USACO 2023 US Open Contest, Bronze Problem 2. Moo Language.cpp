
#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedtime ((double)(clock()-__init_time__)/clocks_per_sec)<<" seconds"
#define ll long long
#define ld long double
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
//Max and Min long long size
const ll mxll = 9223372036854775807, mnll = -9223372036854775807;
//Max and min int size
const int mxint = 2147483647, mnint = -2147483647;
 
void usaco(){
 
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
 
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

int n, c, p, noun, tran, intran, con, n1, t1, i1, c1, ex, cn, ct, ci, cc, ans;
bool f;
string s, t;
void solve(){
	cin >> n >> c >> p;

	//Noun plus intransitive is optimal
	//always use conjunction
	//noun plus transitive plus noun only if there is not enough periods or extra nouns
	//Use commas if nouns cannot be used elsewhere
	
	vector <string> tmp[4];
	noun = 0, tran = 0, intran = 0, con = 0, n1 = 0, t1 = 0, i1 = 0, c1 = 0, ex = 0, cn = 0, ct = 0, ci = 0, cc = 0, ans = 0;
	for (int i = 0; i<n; ++i){
		cin >> s >> t;
    //I mixed up what intransitive and transitive did at the end so i swapped them
		if (t[0] == 'n'){
			++noun;
			tmp[0].push_back(s);
		}else if (t[0] == 'i'){
			++tran;
			tmp[1].push_back(s);
		}else if (t[0] == 't'){
			++intran;
			tmp[2].push_back(s);
		}else if (t[0] == 'c'){
			++con;
			tmp[3].push_back(s);
		}
	}


	t1 = min(tran, min(noun, p + min(con, p)));
	n1 = t1;
	i1 = min(p + min(con, p) - t1, min(intran, (noun - n1) / 2));
	n1 += (i1 * 2);

	while (i1 + t1 < min(con, p) && n1 < noun - 1 && i1 < intran){
		++i1, n1 += 2;
	}
	while (t1 > 0 && n1 < noun && i1 < intran){
		++n1, ++i1, --t1;
	}

	if (i1 == 0 && intran > 0 && ex >= 2){
		++i1, --t1;
		ex = min(c, noun - n1);
	}else if (i1 > 0){
		ex = min(c, noun - n1);
	}
	s = "";
	f = 0;
	while (t1 > 0){
		--t1;
		s += tmp[0][cn];
		s += ' ';
		++cn;
		s += tmp[1][ct];
		++ct;
		ans += 2;

		if (con > 0 && t1 > 0 && f == 0){
			--con;
			s += ' ';
			s += tmp[3][con];
			s += ' ';
			++ans;
			f = 1;
		}else if (con > 0 && i1 > 0 && f == 0){
			--con;
			s += ' ';
			s += tmp[3][con];
			s += ' ';

			s += tmp[0][cn];
			--i1;
			++cn;
			s += ' ';
			s += tmp[2][ci];
			++ci;
			s += ' ';
			s += tmp[0][cn];
			++cn;
			ans += 4;
			while (ex > 0){
				s += ", ";
				s += tmp[0][cn];
				++cn;
				++ans;
				--ex;
			}
			s += ". ";
		}else{
			f = 0;
			s += ". ";
		}
	}
	f = 0;
	while (i1 > 0){
		--i1;
		s += tmp[0][cn];
		++cn;
		s += ' ';
		s += tmp[2][ci];
		++ci;
		s += ' ';
		s += tmp[0][cn];
		++cn;
		ans += 3;
		while (ex > 0){
			--ex;
			s += ", ";
			s += tmp[0][cn];
			++cn;
			++ans;
		}
		if (f == 0 && con > 0 && i1 > 0){
			--con;
			s += ' ';
			s += tmp[3][con];
			s += ' ';
			++ans;
			f = 1;
		}else{
			s += ". ";
			f = 0;
		}
	}
	
	if (s.back() == ' ')
		s.erase(s.size() - 1);
	

	cout << ans << '\n' << s << '\n';
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
	ios::sync_with_stdio(0); cin.tie(0);
	
    int testcases = 1;
	cin >> testcases; 
	for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){
 
		//Google
		//cout<<"Case #"<<number_of_total_test_cases<<": ";
 
		// Normal
		solve();
 
    }
 
	//cout << elapsedTime << '\n';
}
