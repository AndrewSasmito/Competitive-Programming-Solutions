#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int x;
vector <int> v;
int test;
int calc(int i, int mask, int ans){
	//check bit
	//(1<<j) & mask
	
	//base case
	if (i == 4){
		if (ans <= 24)
			return ans;
		else if (ans <=0)
			return ans * -1;
		else
			return 0;
	}

	//choose any of the 4 numbers to start with
	int ret = 0, ret2 = 10000;
	if (i == 0){
		for (int j = 0; j<4; ++j){
			ret = max(ret, calc(i + 1, mask|(1<<j), v[j]));
		}
		return ret;
	}

	for (int j = 0; j<4; ++j){
		for (int k = 0; k<4; ++k){
			if (mask & (1<<k))
				continue;

			if (j == 0){
				//add
				ret = max(ret, calc(i + 1, mask|(1<<k), ans + v[k]));
				test = ans + calc(i + 1, mask|(1<<k), v[k]);
				
				if (test <= 24){
				    ret = max(ret, test);
					ret2 = min(ret2, test);
					ret2 = min(ret2, ret);
				}
			}else if (j == 1){
				//subtract
				ret = max(ret, calc(i + 1, mask|(1<<k), ans - v[k]));
				test = ans - calc(i + 1, mask|(1<<k), v[k]);

				if (test <= 24){
				    ret = max(ret, test);
					ret2 = min(ret2, test);
					ret2 = min(ret2, ret);
				}
			}else if (j == 2){
				//multiply
				ret = max(ret, calc(i + 1, mask|(1<<k), ans * v[k]));
				test = ans * calc(i + 1, mask|(1<<k), v[k]);

				if (test <= 24){
				    ret = max(ret, test);
					ret2 = min(ret2, test);
					ret2 = min(ret2, ret);
				}
			}else if (j == 3){
				//divide
				
				//must become an integer
				if (v[k] > 0){
				    if (ans % v[k] == 0 && ans / v[k] <=24)
					ret = max(ret, calc(i + 1, mask|(1<<k), ans / v[k]));
					ret2 = min(ret, calc(i + 1, mask|(1<<k), ans / v[k]));
				}
                
                if (calc(i + 1, mask|(1<<k), v[k]) > 0){
                    if (ans % calc(i + 1, mask|(1<<k), v[k]) == 0 && ans / calc(i + 1, mask|(1<<k), v[k]) <=24){
					    ret = max(ret, ans / calc(i + 1, mask|(1<<k), v[k]));
						ret2 = min(ret, ans / calc(i + 1, mask|(1<<k), v[k]));
				    }
                }
			}
		}
	}
	return ret;
}

void solve(){

	for (int i = 0; i<4; ++i){
		cin >> x;
		v.push_back(x);
	}	
	
	cout << calc(0, 0, 0) << '\n';
	//bitmask approach?
	v.clear();
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
	cin >> testcases; 
	for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){ 
    


    //Google
    //cout<<"Case #"<<number_of_total_test_cases<<": ";
    // Normal
    solve();
    }

	//cout << elapsedTime << '\n';
}
