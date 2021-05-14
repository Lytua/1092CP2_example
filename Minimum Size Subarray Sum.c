#include <stdio.h>

int main()
{
    int len, target;
    scanf("%d", &len);
    int *arr = (int*)malloc(sizeof(int)*len);
    for (int i=0; i<len; ++i) scanf("%d", &arr[i]);
    scanf("%d", &target);
    
    int res = len + 1, k=0;
    
    for (int i=0; i<len; ++i){
        target -= arr[i];
        while (target <= 0){
            res = ((i - k + 1) < res) ? (i-k+1) : res; 
            target += arr[k++];
        }
    }
    
    printf("%d", res % (len+1));
    
    return 0;
}