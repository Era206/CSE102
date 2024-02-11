#include<stdio.h>
#include<string.h>
int main()
{
    int n, i, j, k=0;
    scanf("%d", &n);
    int a[n][n];
    int b[n][n];
    for(i=0;i<n;i++){
            for(j=0;j<n;j++){
        scanf("%d", &a[i][j]);
            }
    }
    for(i=0;i<n;i++){
            for(j=0;j<n;j++){
        b[j][i]=a[i][j];
            }
    }
    for(i=0;i<n;i++){
            for(j=0;j<n;j++){
    if(b[i][j]!=a[i][j])
    k=1;
            }
    }
    if(k==0)
        printf("YES\n");
    else printf("NO\n");
    return 0;
}
