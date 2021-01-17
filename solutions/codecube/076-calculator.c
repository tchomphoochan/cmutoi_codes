#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);

    if (fabs(a + b - c) < 1e-10)
        printf("Correct");
    else
        printf("Wrong");
    return 0;
}