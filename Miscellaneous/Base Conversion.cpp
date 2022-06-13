#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;


string s1, s2;
set <ll> setter;
ll check1(string s){
	ll ret = 0;

	for (int i = 0; i < s.size(); ++i){
		ret += (s[s.size() - 1 - i] -'0') * pow(2, i);
	}
	return ret;
}

ll check2(string s){
	ll ret = 0;
	for (int i = 0; i < s.size(); ++i){
		ret += (s[s.size() - 1 - i] -'0') * pow(3, i);
	}
	return ret;
}

bool checker(ll x){
	if (setter.find(x) != setter.end()){
		return 1;
	}
	return 0;
}

void solve(){
	cin >> s1 >> s2;

	
	ll temp = check1(s1);

	for (int i = 0; i<s1.size(); ++i){
		if (s1[i] == '0'){
		    s1[i] = '1';
			setter.insert(check1(s1));
			s1[i] = '0';
		}else{
		    s1[i] = '0';
			setter.insert(check1(s1));
			s1[i] = '1';
		}
	}
	
	for (int i = 0; i<s2.size(); ++i){
		if (s2[i] == '2'){
			s2[i] = '1';


			temp = check2(s2);
			if (checker(temp)){
				cout << temp << '\n';
				return;
			}	

			s2[i] = '0';		
			temp = check2(s2);
			if (checker(temp)){
				cout << temp << '\n';
				return;
			}	
			
			s2[i] = '2';
		}else if (s2[i] == '1'){
			s2[i] = '2';		
			temp = check2(s2);
			if (checker(temp)){
				cout << temp << '\n';
				return;
			}	

			s2[i] = '0';		
			temp = check2(s2);
			if (checker(temp)){
				cout << temp << '\n';
				return;
			}	
			
			s2[i] = '1';

		}else{

			s2[i] = '2';		
			temp = check2(s2);
			if (checker(temp)){
				cout << temp << '\n';
				return;
			}	

			s2[i] = '1';		
			temp = check2(s2);
			if (checker(temp)){
				cout << temp << '\n';
				return;
			}	
			
			s2[i] = '0';

		}
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
