#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 6000
#define SIZE2 15

int compare(const void* a, const void* b){
    int va = *(int*)a, vb = *(int*)b;
    if (va>vb) return 1;
    else if (va<vb) return -1;
    return 0;
}

int main()
{
    char *char_num = (char *)malloc(sizeof(char)*SIZE2);
    int *new_its = (int *)malloc(sizeof(int)*SIZE);
    int *old_its = (int *)malloc(sizeof(int)*SIZE);
    char element;
    int k, num, old_top=0, new_top=0, char_num_top=0, count=0;
    scanf("%d", &k);

    while (scanf("%c", &element) != EOF){
        if (element == '\n'){
            ++count;
            free(old_its);
            old_its = new_its;
            old_top = new_top;
            new_its = (int *)malloc(sizeof(int)*SIZE);
            new_top = 0;
        }
        else if (element == ' ') {
            char_num[char_num_top] = '\0'; 
            num = atoi(char_num);
            
            if (count == 1) new_its[new_top++] = num; // first array
            else{
                for (int i=0; i<old_top; ++i){
                    if (old_its[i] == num) {
                        new_its[new_top++] = num;
                        break;
                    }
                }
            }  
            
            free(char_num);
            char_num = (char *)malloc(sizeof(char)*SIZE2);
            char_num_top = 0;
        }
        else{
            char_num[char_num_top++] = element; 
        }
    }
    
    qsort(new_its, new_top, sizeof(int), compare);
    int last = INT_MAX;
    for (int i=0; i<new_top; ++i){
        if (new_its[i] != last){ 
            printf("%d ", new_its[i]);
            last = new_its[i];
        }
    }
    
    return 0;
}