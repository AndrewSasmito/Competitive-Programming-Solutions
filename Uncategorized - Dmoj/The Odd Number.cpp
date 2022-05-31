#include <stdio.h>

long long x = 0, a, n;
int main() {
    scanf("%lld", &n);
    
    for (int i = 0; i<n; ++i){
        scanf("%lld", &a);
        x ^= a;
    }
    printf("%lld\n", x);
}
