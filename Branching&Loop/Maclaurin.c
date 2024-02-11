# include <stdio.h>
int main()
{
    int p, c;
    float q, x, s;
    scanf("%d", &p);
    p = p % 360;
    q = p;
    x = q * 3.141593 / 180;
    float m = (-(x*x)/2.0);
    s = - ((x * x)/ 2.0);
    for(c = 2; c <= 100; c++){
        s =  s * ((- (x * x) / ((2 * c - 1) * 2 * c)));
        m = m + s;
    }
    m = m + 1;
    printf("%f", m);
    return 0;

}

