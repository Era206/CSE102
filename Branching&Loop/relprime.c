# include<stdio.h>
int main()
{
    int n,i,c=0,l;
    scanf("%d", &n);
    for(i=n-1;i>=1;i--){
        int a=n, b=i;
        while(b!=0){
            l=a%b;
            a=b;
            b=l;
        }
        if(a==1)
            c++;
    }
    printf("%d", c);
return 0;
}
