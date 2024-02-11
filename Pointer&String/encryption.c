#include<stdio.h>
#include<string.h>
int main()
{
    int n, i, j;
    scanf("%d", &n);
    void *p;
    p=(char *)malloc(n*sizeof(char));
    //char *q=(char *)p;
    scanf("%s", p);
    for(i=1;i<=n/8;i=i+1){
    printf("%lld ", *((long long int *)(p+i-1)));
    }
    return 0;
}
