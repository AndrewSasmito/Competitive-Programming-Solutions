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

//Max and Min long long size
const ll mxll = 9223372036854775807, mnll = -9223372036854775807;
//Max and min int size
const int mxint = 2147483647, mnint = -2147483647;

void usaco(){

	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);

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
ll psa[3][2000001], ans = mxll, calc, fins, fint, sinp, sint, tinf, tins;
vector <ll> tots(3);
int x, y, z;
string s;
void solve(){
	cin >> s;

	//psa[0] = A
	//psa[1] = B
	//psa[2] = C
	
	for (int i = 1; i<=s.size() * 2; ++i){
		if (s[(i - 1) % s.size()] == 'A'){
			if (i <= s.size()){
				++tots[0];
			}
			++psa[0][i];
		}else if (s[(i - 1) % s.size()] == 'B'){
			if (i <= s.size()){
				++tots[1];
			}
			++psa[1][i];
		}else{
			if (i <= s.size()){
				++tots[2];
			}
			++psa[2][i];
		}

		psa[0][i] += psa[0][i - 1];
		psa[1][i] += psa[1][i - 1];
		psa[2][i] += psa[2][i - 1];
	}

	//ABC, ACB, BCA, BAC, CAB, CBA
	
	for (int i = 1; i<=s.size(); ++i){
		vector <int> pos;
		pos.push_back(0);
		pos.push_back(1);
		pos.push_back(2);
		
		do{
		    calc = 0;
			x = pos[0], y = pos[1], z = pos[2];
			
			fins = psa[x][i + tots[x] + tots[y] - 1] - psa[x][i + tots[x] - 1];
			fint = psa[x][i + tots[x] + tots[y] + tots[z] - 1] - psa[x][i + tots[x] + tots[y] - 1];

			sinp = psa[y][i + tots[x] - 1] - psa[y][i - 1];
			sint = psa[y][i + tots[x] + tots[y] + tots[z] - 1] - psa[y][i + tots[x] + tots[y] - 1];

			tinf = psa[z][i + tots[x] - 1] - psa[z][i - 1];
			tins = psa[z][i + tots[x] + tots[y] - 1] - psa[z][i + tots[x] - 1];


			//cout << "STATS:\n";
			//cout << "Positions: " << pos[0] << ' ' << pos[1] << ' ' << pos[2] << '\n';
			//cout << "Numbers: " << fins << ' ' << fint << ' ' << sinp << ' ' << sint << ' ' << tinf << ' ' << tins << '\n';
			//First and second
			calc += min(fins, sinp);
			fins = max(fins, sinp) - min(fins, sinp);

			//first and third
			calc += min(fint, tinf);
			fint = max(fint, tinf) - min(fint, tinf);

			//second and third
			calc += min(sint, tins);
			sint = max(sint, tins) - min(sint, tins);

			calc += ((fins + fint + sint) / 3) * 2;
			//cout << "Score: " << ans << ' ' << calc << '\n';
			//cout << "Index: " << i << '\n';
			ans = min(calc, ans);
		}while(next_permutation(pos.begin(), pos.end()));
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
	ios::sync_with_stdio(0); cin.tie(0);
	
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
