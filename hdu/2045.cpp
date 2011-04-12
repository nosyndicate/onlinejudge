//http://acm.hdu.edu.cn/showproblem.php?pid=2045
#include <stdio.h>
int main()
{
    __int64 a[51];
    a[1] = 3,a[2] = 6,a[3] = 6;
    for(int i = 4;i<51;++i)
    {
        a[i] = a[i-1]+2*a[i-2];
    }
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%I64d\n",a[n]);
    }
    return 0;
}
/*
1.若前n-1合法，则首尾不同，再添1个时，只有1种方法；
2.若前n-1不合法，而添1个时合法，即只是因为首尾相同引起的不合法，这样前n-2必定合法。此时第n个的添加有2种方法。
3.f(1)=3;f(2)=6;f(3)=6.
*/