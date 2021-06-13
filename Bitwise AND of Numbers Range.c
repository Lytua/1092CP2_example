#include <stdio.h>

int main()
{
    
    int m, n, ans;
    scanf("%d %d", &m, &n);

    int i = 0; // i means we have how many bits are 0 on the right
    while(m != n){
        m >>= 1;
        n >>= 1;
        i++;  
    }  
    printf("%d", m<<i);
    return 0;
}