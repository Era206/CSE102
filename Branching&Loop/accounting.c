# include<stdio.h>
int main()
{
    int x;
    float y;
    scanf("%d", &x);
    if(x<=100)
        y=x*0.5;
    else if(x<=200)
        y=100*0.5+(x-100)*0.8;
    else
        y=100*(0.5+0.8)+(x-200)*1.2;
    printf("%.2f", y);
    return 0;
}
