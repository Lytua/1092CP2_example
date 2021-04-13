// Kadane's Algorithm

#include <stdio.h>
#define SIZE 100000 
int main()
{
    int arr[SIZE];
    int n = 0;
    int m;
    // read input 
    while (scanf("%d", &m) != EOF){
        arr[n] = m;
        ++n;
    }
    
    
    int temp_max=0, max_gap=0;
    for (int i=1; i<n; ++i){
        temp_max = (temp_max + (arr[i] - arr[i-1]) > 0) ? temp_max + (arr[i] - arr[i-1]) : 0;
        max_gap = (temp_max > max_gap) ? temp_max : max_gap;
    }
    
    printf("%d", max_gap);

    return 0;
}