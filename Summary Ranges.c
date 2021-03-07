#include <stdio.h>

int main() {
    int num;
    int nums[20];
    int numsSize=0;
    // input data
    while(scanf("%d", &num) != EOF){
        nums[numsSize] = num;
        numsSize++;
    }
    
    
    if (numsSize == 0){
        // printf();
        return 0;
    }
    
    int reset_left = 1;
    int left, right;
    int count = 1; 
    
    for (int i=0; i<numsSize; ++i){
        if (reset_left){
            left = nums[i];
            reset_left = 0;
        } 
        
        if (i<numsSize-1){
            right = nums[i+1];
            if ((left+count) == right){
                count += 1;
            }
            else{
                if (count == 1){
                    printf("%d\n", nums[i]);
                }
                else{
                    printf("%d->%d\n", left, nums[i]);   
                }
                reset_left = 1;
                count = 1;
            }
        
        } 
        else{ // i=numsSize-1
            right = nums[i];
            if (count == 1){
                printf("%d\n", nums[i]);
            }
            else{
                printf("%d->%d\n", left, nums[i]);   
            }
        }
    }
    return 0;
}
