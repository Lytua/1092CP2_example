#include <stdio.h>
#define DIR_SIZE 4

typedef struct Node{
    int a;
    int b;
}node;

int dfs(int i, int j, int n, int m, int **arr, int **dp, node *dir); 
void print_route(int i, int j, int n, int m, int **dp, node *dir);

int dfs(int i, int j, int n, int m, int **arr, int **dp, node *dir){
    if (dp[i][j]) return dp[i][j];
    
    int ii, jj, x;
    for (int k=0; k<DIR_SIZE; ++k){
        ii = i+dir[k].a;
        jj = j+dir[k].b;
        if (ii>=0 && ii<n && jj>=0 && jj<m && arr[ii][jj] > arr[i][j]){
            x = dfs(ii, jj, n, m, arr, dp, dir);
            dp[i][j] = (x > dp[i][j]) ? x : dp[i][j]; 
        }
    }
    return ++dp[i][j];
}

void print_route(int i, int j, int n, int m, int **dp, node *dir){
    printf("\n%d %d", i, j);
    if (dp[i][j] == 1) return;
    
    int ii, jj;
    for (int k=0; k<DIR_SIZE; ++k){
        ii = i+dir[k].a;
        jj = j+dir[k].b;
        if (ii>=0 && ii<n && jj>=0 && jj<m && dp[ii][jj] == dp[i][j]-1){
            break;
        }
    }
    print_route(ii, jj, n, m, dp, dir);
    return;
}


int main()
{
    int n, m, longest_path=0, x, l_i=0, l_j=0;
    scanf("%d %d", &n, &m);
    int **arr = (int **)malloc(sizeof(int*)*n);
    int **dp = (int **)malloc(sizeof(int*)*n);
    for (int i=0; i<n; ++i){
        arr[i] = (int *)malloc(sizeof(int)*m);
        for (int j=0; j<m; ++j) scanf("%d", &arr[i][j]);
        dp[i] = (int *)malloc(sizeof(int)*m);
    }
    
    node* dir;
    dir = (node*)malloc(sizeof(node)*DIR_SIZE);
    dir[0].a = -1;
    dir[0].b = 0;
    dir[1].a = 1;
    dir[1].b = 0;
    dir[2].a = 0;
    dir[2].b = -1;
    dir[3].a = 0;
    dir[3].b = 1;
    
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            x = dfs(i, j, n, m, arr, dp, dir);
            if (x > longest_path){
                longest_path = x, l_i=i, l_j=j;
            }
        }
    }
    
    printf("%d", longest_path);
    print_route(l_i, l_j, n, m, dp, dir);
    return 0;
}