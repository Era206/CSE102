#include<stdio.h>
#include<string.h>
int main()
{
    int n1, n2, i, j, k, c=0;
    char s1[100];
    char s2[100];
    gets(s1);
    gets(s2);
    n1=strlen(s1);
    n2=strlen(s2);
    for(i=0;i<n1;i++){
        if(s1[i]==s2[0]){
                int m=0;
            for(j=0, k=i;j<n2, k<i+n2;j++, k++){
                if(s2[j]!=s1[k])
                    m=1;
            }
        if(m==0)
            c++;

       }
    }
    printf("%d", c);
    return 0;
}

