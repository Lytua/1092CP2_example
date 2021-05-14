#include <stdio.h>
#include <limits.h>

int find_median(int *a_arr, int *b_arr, int la, int ra, int lb, int rb, int m);

int find_median(int *a_arr, int *b_arr, int la, int ra, int lb, int rb, int m){
    if (la >= ra){
        return b_arr[lb + m - 1];
    }
    if (lb >= rb){
        return a_arr[la + m - 1];
    }
    if (m == 1){
        return a_arr[la] <= b_arr[lb] ? a_arr[la] : b_arr[lb]; 
    }
    
    int a_mid_i = la + m/2 -1, b_mid_i = lb + m/2 -1;
    int a_mid = (a_mid_i >= ra) ? (INT_MAX) : a_arr[a_mid_i];
    int b_mid = (b_mid_i >= rb) ? (INT_MAX) : b_arr[b_mid_i];
    
    if (a_mid > b_mid){
        find_median(a_arr, b_arr, la, ra, lb + m/2, rb, m - m/2);
    }
    else{
        find_median(a_arr, b_arr, la + m/2, ra, lb, rb, m - m/2);
    }
    
    return;
}

int main()
{
    int a_len, b_len;
    scanf("%d", &a_len);
    int *a_arr = (int*)malloc(sizeof(int)*a_len);
    for (int i=0; i<a_len; ++i) scanf("%d", &a_arr[i]);
    scanf("%d", &b_len);
    int *b_arr = (int*)malloc(sizeof(int)*b_len);
    for (int i=0; i<b_len; ++i) scanf("%d", &b_arr[i]);
    
    int q_count, la, ra, lb, rb, q_len, odd, m, median1, median2;
    scanf("%d", &q_count);
    for (int i=0; i<q_count; ++i){
        scanf("%d %d %d %d", &la, &ra, &lb, &rb);
        q_len = (ra - la) + (rb - lb);
        odd = q_len % 2;
        
        if (odd){
            median1 = find_median(a_arr, b_arr, la, ra, lb, rb, q_len/2 + 1);
            printf("%d\n", median1);
        }
        else{
            median1 = find_median(a_arr, b_arr, la, ra, lb, rb, q_len/2);
            median2 = find_median(a_arr, b_arr, la, ra, lb, rb, q_len/2 + 1);
            printf("%d %d\n", median1, median2);
        }
    }
    
    return 0;
}
