#include<stdio.h>
#include<string.h>
#include<math.h>
    void abc(float a, float b, float c,int* s){
        *s=0;
        *(s+1)=0;
        if(a+b>c&&b+c>a&&c+a>b){
            *s=1;
            float i=a*a+b*b, j=b*b+c*c, k=c*c+a*a;
            if(i==c*c||j==a*a||k==b*b)
             *(s+1)=1;
        }

    }
    int main()
    {
        float a, b, c;
        scanf("%f%f%f", &a, &b, &c);
        int* p[2];
        abc(a,  b, c, p);
        if (*p==0)
            printf("NOT TRIANGLE\n");
        else
        {
            if(*(p+1)==1)
                printf("TRIANGLE AND RIGTH ANGLE\n");
            else
                printf("TRANGLE BUT NOT RIGHT ANGLE\n");
        }
    return 0;
}
