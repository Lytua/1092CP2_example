#include <stdio.h>
long long int modulo(long long int a, long long int b, long long int n);

long long int modulo(long long int a, long long int b, long long int n){
    long long int x=1, y=a; 
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % n; // multiplying with base
        }
        y = (y*y) % n; // squaring the base
        b /= 2;
    }
    return x % n;
}

int main()
{
    long long int n, x, y, p, ans;
    scanf("%lli", &n);
    
    for (int i=0;i<n; ++i){
        scanf("%lli", &x);
        scanf("%lli", &y);
        scanf("%lli", &p);
        
        if (y == 0){
            printf("%d\n", 1 % p);
            continue;
        }
        
        ans = modulo(x, y, p);
        
        printf("%lli\n", ans);
    }

    return 0;
}