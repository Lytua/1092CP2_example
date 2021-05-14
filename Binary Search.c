#include <stdio.h>

void binarySearch(int *arr, int arr_len,int target, int *index, int *step);

void binarySearch(int *arr, int arr_len, int target, int *index, int *step){
    if (arr == NULL || arr_len == 0){
        *index = -1;
        return;
    }
    
    int left = 0, right = arr_len, mid;
    while (left < right){
        ++*step;
        mid = left + (right-left)/2;

        if (arr[mid] == target){
            *index = mid;
            return;
        }
        else if (arr[mid] > target){
            right = mid;
        }
        else if (arr[mid] < target){
            left = mid + 1;
        }
    }
    
    if (left != arr_len && arr[left] == target){
        *index = left;
        return;
    }
    else{
        *index = -1;
        return;
    }
}

int main()
{
    int target, num, arr_len = 0, size = 100000000;
    int index = -1, step = 0;
    int *index_p = &index, *step_p = &step;
    int *arr = (int *)malloc(sizeof(int)*size);
    scanf("%d", &target);
    while (scanf("%d", &num) != EOF){
        arr[arr_len] = num;
        ++arr_len;
    }
    
    binarySearch(arr, arr_len, target, index_p, step_p);
    
    if (*index_p == -1) printf("%d\n", *index_p);
    else{
        printf("%d\n", *index_p);
        printf("%d\n", *step_p);
    }
    
    return 0;
}
