#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int n, k, x;
int dp[1000001];
map <int, int> m;
int main(){
    scan(n);
    scan(k);

	for (int i = 0; i<n; ++i){
		scan(dp[i]);
	}
	
	long long cur = 0;
	int mod, ans = 0;
	for (int i = 0; i<n; ++i){
		cur += dp[i];
		
		mod = ((cur % k) + k) % k;

		if (mod == 0){
			ans = i + 1;
		}else if (m.find(mod) == m.end()){
			m[mod] = i;
		}else{
		    if (ans < i - m[mod])
			    ans = i - m[mod];
		}

	}
	
	if (ans == 0){
		printf("-1\n");
	}else{
		printf("%d", ans);
	}
}
