#include <stdio.h>
#include <limits.h>

int cmpfunc(const void *a_p, const void *b_p){
    float a = *(const float*)a_p;
    float b = *(const float*)b_p;
    return (a > b) ? 1 : -1;
}

int main()
{
    int n, k, same, max=2;
    float last_slope;
    scanf("%d", &n);
    if (n==1){
        printf("%d", 0);
        return 0;
    }
    
    int *x = (int *)malloc(sizeof(int)*n);
    int *y = (int *)malloc(sizeof(int)*n);
    int slope_len = n-1;
    float *slope = (float *)malloc(sizeof(float)*(slope_len));
    
    for (int i=0; i<n; ++i){
        scanf("%d", x+i);
        scanf("%d", y+i);
    }
    
    for (int i=0; i<n; ++i){
        k = 0;
        for (int j=0; j<n; ++j){
            if (i != j){
                if (y[i] == y[j]) slope[k] = 0.0;
                else if (x[i] == x[j]) slope[k] = INT_MAX;
                else slope[k] = (float)(y[i] - y[j])/(float)(x[i] - x[j]); // debug:負斜率
                ++k;
            }
        }
        
        qsort(slope, slope_len, sizeof(float), cmpfunc);
        
        last_slope = -1.0;
        for (int j=0; j<slope_len; ++j){
            if (slope[j] != last_slope){
                last_slope = slope[j];
                same = 2;
            }
            else{
                ++same;
                if (same > max) max = same;
            }
        }
    }
    
    printf("%d", max);
    return 0;
}