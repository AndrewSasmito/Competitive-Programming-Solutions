#include <stdio.h>
int n, x, dp[10001];
int main(){
    scanf("%d", &n);

	for (int i = 0; i<n; ++i){
		scanf("%d", &x);
		++dp[x];
	}

	for (int i = 1; i<=10000; ++i){
        for (int j = 0; j < dp[i]; ++j)
            printf("%d\n", i);
	}
}
