//http://acm.hdu.edu.cn/showproblem.php?pid=2502
#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int t;
        scanf("%d",&t);
        double first = pow((double)2,(double)t-1);
        double second = first*(t-1)/2;
        printf("%d\n",(int)(first+second));
    }
    return 0;
}