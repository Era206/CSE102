#include<stdio.h>
int main()
{
    int n, e=0, o=0, i;
    scanf("%d", &n);
     int *p=(int*)malloc(n*sizeof(int));
    //int *p = a;
    for(i=0;i<n;i++){
        scanf("%d", p+i);
        if((i+1)%2==0)
            o+= *(p+i);
        else
            e+= *(p+i);
    }
    if(e<o)
        printf("Odd index sum is greater\n");
    else if(e>o)
        printf("Even index sum is greater\n");
    else printf("Equal\n");
    return 0;
}
