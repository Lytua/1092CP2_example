#include <stdio.h>
#include <limits.h>
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n+1];
    for (int i = 0; i<=n; ++i){
        arr[i] = INT_MAX;
    }
    arr[0] = 0;
    
    
    for (int i = 1; i<=n; ++i){
        for (int j = 1; j*j<=i; ++j){
            arr[i] = (arr[i] < (1+arr[i-j*j])) ? arr[i]:(1+arr[i-j*j]);   // min()
        }
    }
    
    printf("%d", arr[n]);
    return 0;
}