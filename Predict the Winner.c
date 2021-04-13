// https://leetcode.com/problems/predict-the-winner/discuss/96828/JAVA-9-lines-DP-solution-easy-to-understand-with-improvement-to-O(N)-space-complexity.
#include <stdio.h>
int main()
{
    
    int n;
    scanf("%d", &n);
    
    int *num = (int *)malloc(sizeof(int)*n);
    
    int **dp = (int **)malloc(sizeof(int *)*n);
    for (int i=0; i<n; ++i){
        dp[i] = (int *)malloc(sizeof(int)*n);
    }
    
    for (int i=0; i<n; ++i){
        scanf("%d", &num[i]);
        dp[i][i] = num[i];
    }

    
    int j;
    for (int k=1; k<n; ++k){
        for (int i=0; i<n-k; ++i){
            j = i + k;
            dp[i][j] = (num[i] - dp[i+1][j] > num[j] - dp[i][j-1]) ? num[i] - dp[i+1][j] : num[j] - dp[i][j-1];
        }
    }
    
   
    (dp[0][n-1] >= 0) ? printf("%s", "True") : printf("%s", "False");
    

    return 0;
}