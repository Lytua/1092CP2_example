#include <stdio.h>
#define SIZE 1000000
int main()
{
    int n;
    int arr[SIZE] = {0};
    int num;
    

    scanf("%d", &n);
    for (int i=0; i<n; ++i){
        scanf("%d", &num);
        
        if (num >= 0){
            arr[num] = arr[num] + 1;
        }
    }
    
    unsigned long long int  max = 0;
    unsigned long long int  value = 0;
    unsigned long long int  sum = 0; 
    for (int i=0; i<SIZE; ++i){
        if (i*arr[i] > max){
            value = i;
            max = i*arr[i];
        }
    }
    
    sum = max * 10000;
    
    printf("%llu\n", value);
    printf("%llu", sum);
    return 0;
}