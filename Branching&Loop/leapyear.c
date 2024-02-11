# include<stdio.h>
int main()
{
    int y, c;
    scanf("%d", &y);
    c=y%400==0?printf("Leap year"):y%100!=0?y%4==0?printf("Leap year"):
        printf("Not a leap year"):printf("Not a leap year");
        return 0;
}
