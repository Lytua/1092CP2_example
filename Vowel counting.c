#include <stdio.h>
#include <string.h>
#define SIZE 5
int main()
{
    int n;
    scanf("%d", &n);
    
    int arr[SIZE];
    
    for (int i=0; i<SIZE; ++i){
        arr[i] = 1;
    }
    

    for (int i=1; i<n; ++i){
        for (int j=1; j<SIZE; ++j){
            arr[j] += arr[j-1];
        }  
    }
    
    unsigned int sum = 0;
    for (int i=0; i<SIZE; ++i){
        sum += arr[i];
    }
    
    printf("%u", sum);
    return 0;
}