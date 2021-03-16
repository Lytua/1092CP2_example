#include <stdio.h>
#define SIZE 100000

int main()
{
    int arr[SIZE];
    for (int i = 0; i<SIZE; ++i){
        arr[i] = -1;
    }
    
    int sum[SIZE+1];
    int table[SIZE+1];
    int max_sum = 0;
    int window_sum = 0;
    int start = 0, end = 0;
    // input arr[] & update sum[]
    int num;
    int i=0;
    while(scanf("%d", &num) != EOF){
        arr[i] = num;
        sum[i+1] = arr[i] + sum[i];
        ++i;
    }
    
    
    while (end < SIZE && arr[end] != -1){
        // move end, if duplicate => stop end
        for (;end < SIZE && arr[end] != -1; ++end){
            if (table[arr[end]] > 0){
                break;
            }
            table[arr[end]]++;
        }    
        
        window_sum = sum[end] - sum[start]; 
        max_sum = (window_sum > max_sum) ? window_sum : max_sum;
        
        if (end < SIZE && arr[end] != -1){
            // update table, start
            while (start < end && arr[end] != arr[start]){
                table[arr[start]] = 0;
                start++;
            }
            table[arr[start]] = 0;
            start++;
        }
    }
    
    printf("%d", max_sum);
    return 0;
}