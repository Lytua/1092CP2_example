#include <stdio.h>
#include <string.h>
#define SIZE 26
int main()
{
    int stack_top=-1, stack_len = 0, elim_num=0;
    char str[SIZE];
    char stack_arr[SIZE];
    char elim_arr[SIZE];
    for (int i=0; i<SIZE; ++i){
        stack_arr[i] = -1;
        elim_arr[i] = 0; 
    }
    
    scanf("%s", str);
    for (int i=0; i<strlen(str); ++i){
        if (str[i] == '('){ // not yet match
            ++stack_len;
            stack_arr[++stack_top] = i;
        }
        else if(str[i] == ')' && stack_top>=0){  // match
            --stack_len;
            stack_arr[stack_top] = -1;
            --stack_top;
        }
        else if(str[i] == ')' && stack_top<0){
            elim_arr[elim_num] = i; // elim
            ++elim_num;
        }
    }
    
    for (int i=0; i<stack_len; ++i){
        str[stack_arr[i]] = '1';  //elim
    }
    for (int i=0; i<elim_num; ++i){
        str[elim_arr[i]] = '1'; //elim
    }
    
    // print result
    int new_str_len = 0;
    for (int i=0; i<strlen(str); ++i){
        if (str[i] != '1'){
            printf("%c", str[i]);
            ++new_str_len;
        }
    }
    //if (new_str_len == 0) printf("%s", "\n"); 
    
    return 0;
}