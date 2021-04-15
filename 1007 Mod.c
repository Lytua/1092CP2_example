#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    long long a, b;
    long long c = 1007;
    long long sum;
    scanf("%d", &t);
    for (int i=0; i<t; ++i){
        sum = 1;
        scanf("%ld", &a);
        scanf("%ld", &b);
        a%=c;
        while(b>0){
        	if(b&1) sum=sum*a%c;
        	a=a*a%c;
        	b>>=1;
        }
    	printf("%ld\n",sum);
    }


    return 0;
}