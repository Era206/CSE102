# include<stdio.h>
int main()
{
    int c=0, q=0,p=-1, x=0;
        char n;
        while(n!='\n'){
        scanf("%c", &n);
        x=n;
        q=x-48;
        if(q>p){
            p=q;
            c=0;
        }
        if(p==q){
            c++;
        }
        }
        printf("%d", c);
    return 0;
}

