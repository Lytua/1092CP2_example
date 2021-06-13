#include <stdio.h>
#include <string.h>
#define SIZE 100
int main()
{
    char s[SIZE], p[SIZE];
    fgets(s, SIZE, stdin);
    fgets(p, SIZE, stdin);
    int s_len = strlen(s)-1, p_len = strlen(p);
    int **dp = (int**)malloc(sizeof(int*)*(s_len+1));
    for (int i=0; i < s_len+1; ++i){
        dp[i] = (int*)malloc(sizeof(int)*(p_len+1));
    }
    
    dp[0][0] = 1;
    for (int i=1; i<s_len+1; ++i) dp[i][0] = 0;
    for (int i=1; i<p_len+1; ++i) {
        if (p[i-1] == '*') dp[0][i] = dp[0][i-2];
        else dp[0][i] = 0;
    }
    for (int i=1; i<s_len+1; ++i){
        for (int j=1; j<p_len+1; ++j){
            if (s[i-1] == p[j-1] || p[j-1] == '.') dp[i][j] = dp[i-1][j-1];
            else if (p[j-1] == '*'){
                dp[i][j] = dp[i][j-2]; //*0個
                if (s[i-1] == p[j-2] || p[j-2] == '.'){ // *無數個
                    dp[i][j] = dp[i][j] | dp[i-1][j];
                }
            }
            else dp[i][j] = 0;
        }
    }
    
    printf((dp[s_len][p_len]) ? "true" : "false");
    return 0;
}
