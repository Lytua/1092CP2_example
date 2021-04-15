#include <stdio.h>

int arr[100010];

int main()
{
    unsigned int n, sumL, sumR, count = 0;
    scanf("%u", &n);
    for (int i = 0; i < n; ++i) scanf("%u", &arr[i]);
    sumL = arr[0], sumR = arr[n - 1];
    
    
    for (int l = 0, r = n - 1; l < n && r>=0;){
        if (sumL > sumR) sumR += arr[--r];
        else if (sumR > sumL) sumL += arr[++l];
        else if (arr[l] == 0 && arr[r] == 0){
            sumR += arr[--r];
            sumL += arr[++l];
        }
        else{
            sumR += arr[--r];
            sumL += arr[++l];
            ++count;
        }
    }
    printf("%u", count);
    return 0;
}