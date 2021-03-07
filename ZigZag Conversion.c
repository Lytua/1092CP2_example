
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int numRows;
    char s[1001];
    scanf("%s", s);
    scanf("%d", &numRows);
    
    int n=strlen(s);
    if (numRows == 1 || numRows >= n){
        printf("%s", s);
        return 0;
    }

    int j;
    int k = 0;
    bool up;
    int next_step;
    char a[1001]; 
    
    for (int i=1; i<numRows+1; ++i){
        j = i-1;
        up = false;
        while(j < n){
            a[k] = s[j];
            k++;
            
            if (up){ //up
                next_step = (i == 1) ? (numRows-1)*2 : (i-1)*2; 
                up = false;
            }
            else{ // down
                next_step = (i == numRows) ? (numRows-1)*2 : (numRows - i)*2;
                up = true;
            }
            
            j += next_step;
        }
    }
    
    a[k++] = '\0';
    printf("%s", a);
    return 0;
}
