#include <stdio.h>
#include <string.h>
#define SIZE 100001
int main()
{
    char arr[SIZE];
    char ans[SIZE];
    char left, right;
    int len, j, k;
    fgets(arr, SIZE, stdin);
    len = strlen(arr);
 
    for (int i=0; i<len; ++i){
        if (arr[i] == 'L' || arr[i] == 'R'){
            ans[i] = arr[i];
            continue;
        }
        
        // look left and right
        j = i-1;
        k = i+1;
        while (1){
            // left and right would not affect outcome
            if ((j < 0 && k >= len) || (arr[j] == 'L' && arr[k] == 'R') || (arr[j] == 'L' && k >= len) || (j < 0 && arr[k] == 'R')){
                ans[i] = '.';
                break;
            }
            
            // left would not affect outcome
            if (j < 0 || arr[j] == 'L'){ 
                left = '.';
                j++;
            }
            else{
                left = arr[j];
            }
            // right would not affect outcome
            if (k >= len || arr[k] == 'R'){ 
                right = '.';
                k--;
            }
            else{
                right = arr[k];
            }
            

            // stay
            if (left == 'R' && right == 'L'){ 
                ans[i] = '.';
                break; 
            }
            // fall right
            else if (left == 'R' && right == '.'){ 
                ans[i] = left; 
                break;
            }
            // fall left
            else if (left == '.' && right == 'L'){
                ans[i] = right;
                break;
            }
            
            j--;
            k++;
        }
    }
    
    puts(ans);

    return 0;
}