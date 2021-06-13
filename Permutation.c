#include <stdio.h>

int permutation(int n, int k, int depth, int *chosen, int *ans, int *count, int *found);

int permutation(int n, int k, int depth, int *chosen, int *ans, int *count, int *found){
    if (depth == n-1){
        if (++*count == k){
            *found = 1;
            for (int i=0; i<n-1; ++i) printf("%d", ans[i]);
            for (int i=0; i<n; ++i){
                if (!chosen[i]){
                    printf("%d", i+1);
                }
            }
        }
        return;
    }
    
    for (int i=0; i<n; ++i){
        if (*found) break; 
        if (chosen[i]) continue;
        
        chosen[i] = 1;
        ans[depth] = i+1;
        permutation(n, k, depth+1, chosen, ans, count, found);
        
        chosen[i] = 0;
    }
    
    return;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    
    int *chosen = (int*)malloc(sizeof(int)*n);
    int *ans = (int*)malloc(sizeof(int)*n);
    
    int count=0, found=0;
    int *count_p = &count, *found_p = &found;
    
    permutation(n, k, 0, chosen, ans, count_p, found_p);

    return 0;
}
