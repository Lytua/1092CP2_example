#include <stdio.h>
#include <stdbool.h>
int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        int *a_arr = (int *)malloc(sizeof(int)*n);
        int *b_arr = (int *)malloc(sizeof(int)*n);
        int *station = (int *)malloc(sizeof(int)*(n+1));
        for (int i=0; i<n; ++i){
            a_arr[i] = (i+1);
        }
        for (int i=0; i<n; ++i){
            scanf("%d", &b_arr[i]);
        }
        
        int input = 0;
        int output = 0;
        int top = 0;
        bool NIE = false;
        
        while(output < n){
            if (input == n || a_arr[input] > b_arr[output]){
                if (b_arr[output] == station[top]){
                    --top;
                    ++output;
                }
                else {
                    printf("%s", "NIE\n");
                    NIE = true;
                    break;
                }
            }
            else if (a_arr[input] == b_arr[output]){
                ++input;
                ++output;
            }
            else if (a_arr[input] < b_arr[output]){
                station[++top] = a_arr[input];
                ++input;
            
        }
        
        if (!NIE){
            printf("%s", "TAK\n");
        }
    }

    return 0;
}