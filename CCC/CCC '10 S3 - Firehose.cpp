#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int x, h, y, k;
vector <int> hold;
int check(int z){
	int ret = 1000000;
	int diameter = 2 * z;

	for (int i = 0; i<x; ++i){
		int cnt = 1;
		if (hold[0] + diameter < hold[i]){
			break;
		}
		int cur = hold[i];

		for (int j = i + 1; j<x; ++j){
			if (hold[j] + diameter - 1000000 >= hold[i]){
				break;
			}
			if (hold[j] > cur){
				cur = hold[j] + diameter;
				++cnt;
			}
		}
		ret = min(ret, cnt);
	}
	return ret;
}

void solve(){
	cin >> x;


	for (int i = 0; i<x; ++i){
		cin >> y;
		hold.push_back(y);
	}
	cin >> k;
	sort(hold.begin(), hold.end());

	int hi =  1000000, lo = 0;
	while (lo <= hi -1){
		int mid = (hi + lo) / 2;
		if (check(mid) > k){
			lo = mid+1;
		}else{
			hi = mid;
		}
	}

	cout << hi << '\n';
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
