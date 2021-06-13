// https://leetcode.com/problems/making-a-large-island/discuss/127032/C%2B%2BJavaPython-Straight-Forward-O(N2)-with-Explanations
#include <stdio.h>

void find_max(int **arr, int **area_index, int i, int j, int n, int index, int *count_p);
void count_land_sum(int i, int j, int n, int *count_p, int *area, int **area_index, int *confirm_index);

void find_max(int **arr, int **area_index, int i, int j, int n, int index, int *count_p){
    if (i>=0 && i<n && j>=0 && j<n && !area_index[i][j] && arr[i][j]){
        area_index[i][j] = index;
        ++*count_p;
        find_max(arr, area_index, i-1, j, n, index, count_p);
        find_max(arr, area_index, i+1, j, n, index, count_p);
        find_max(arr, area_index, i, j-1, n, index, count_p);
        find_max(arr, area_index, i, j+1, n, index, count_p);
    }
    return;
}


void count_land_sum(int i, int j, int n, int *count_p, int *area, int **area_index, int *confirm_index){
    if (i>=0 && i<n && j>=0 && j<n && area_index[i][j] && confirm_index[area_index[i][j]] == 0){
        *count_p += area[area_index[i][j]];
        ++confirm_index[area_index[i][j]];
    }  
    return;
}



int main()
{
    int n, max_land = 0, count, *count_p = &count;
    scanf("%d", &n);
    int **arr = (int**)malloc(sizeof(int*)*n);
    int *confirm_index = (int*)malloc(sizeof(int)*(n*n+1));
    int *area = (int*)malloc(sizeof(int)*(n*n+1));
    int **area_index = (int**)malloc(sizeof(int*)*n);
    
    for (int i=0; i<n; ++i){
        arr[i] = (int*)malloc(sizeof(int)*n);
        for (int j=0; j<n; ++j) scanf("%d", &arr[i][j]);
        area_index[i] = (int*)malloc(sizeof(int)*n);
    }
    
    // dfs
    int index = 1;
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            if (arr[i][j] == 1 && !area_index[i][j]){
                *count_p = 0;
                find_max(arr, area_index, i, j, n, index, count_p);
                area[index] = *count_p; 
                ++index;
            }
        }
    }
    
    // count adjcent land
    int zero_count = 0;
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            if (arr[i][j] == 0){
                ++zero_count;
                *count_p = 1;
                memset(confirm_index, 0, (n*n+1)*sizeof(int));
                count_land_sum(i-1, j, n, count_p, area, area_index, confirm_index);
                count_land_sum(i+1, j, n, count_p, area, area_index, confirm_index);
                count_land_sum(i, j-1, n, count_p, area, area_index, confirm_index);
                count_land_sum(i, j+1, n, count_p, area, area_index, confirm_index);
                max_land = (*count_p > max_land) ? *count_p : max_land;
            }
        }
    }
    
    if (zero_count == 0) printf("%d", n*n);
    else printf("%d", max_land);
    
    return 0;
}
