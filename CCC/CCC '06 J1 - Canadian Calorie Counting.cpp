#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

vector <int> v1 = {461, 431, 420, 0};
vector <int> v2 = {100, 57, 70, 0};
vector <int> v3 = {130, 160, 118, 0};
vector <int> v4 = {167, 266, 75, 0};
int n, ans = 0;
void solve(){
	cin >> n;
	ans += v1[n-1];
	cin >> n;
	ans += v2[n-1];
	cin >> n;
	ans += v3[n-1];
	cin >> n;
	ans += v4[n-1];
	cout << "Your total Calorie count is " << ans << '.' << '\n';
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
