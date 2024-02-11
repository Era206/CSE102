#include<stdio.h>
int main()
{
    int n, maxc=0, mode=0, i, j, k=0;
    scanf("%d", &n);
    //int a [n];
    int *p = (int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d", p+i);
    }
    for(i=0;i<n;i++){
        int c=0;
        for(j=0;j<n;j++){
            if(*(p+j)==*(p+i))
                c++;
        }
        if(c>maxc){
            maxc=c;
            //mode=*(p+i);
        }
    }
    //printf("%d", mode);
    for(i=0;i<n;i++){
            int c1=1;
        for(j=i+1;j<n;j++){
            if(*(p+j)==*(p+i))
                c1++;
        }
        if(c1==maxc)
            printf("%d ", *(p+i));
    }
    return 0;
}
