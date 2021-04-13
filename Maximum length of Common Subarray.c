// DP Solution

#include <stdio.h>
#define SIZE 1000
int main()
{
    int arr_A[SIZE];
    int arr_B[SIZE];
    int a_len, b_len;
    // read input
    scanf("%d", &a_len);
    for (int i=0; i<a_len; ++i){
        scanf("%d", &arr_A[i]); 
    }
    scanf("%d", &b_len);
    for (int i=0; i<b_len; ++i){
        scanf("%d", &arr_B[i]);
    }
    
    int dp[a_len+1][b_len+1];
    memset(dp, 0, sizeof(dp[0][0])*(a_len+1)*(b_len+1));
    int k = 0;
    
    for (int i=0; i<a_len; ++i){
        for (int j=0; j<b_len; ++j){
            if (arr_A[i] == arr_B[j]){
                dp[i+1][j+1] = dp[i][j]+1;
                k = (dp[i+1][j+1] > k) ? (dp[i+1][j+1]) : k;
            }
            else{
                dp[i+1][j+1] = 0;
            }
        }
    }

    printf("%d", k);
    return 0;
}