//http://acm.hdu.edu.cn/showproblem.php?pid=2047
#include <stdio.h>
int main()
{
    __int64 a[41],b[41];
    a[1] = 1,b[1] = 2;
    for(int i = 2;i<41;++i)
    {
        a[i] = b[i-1];
        b[i] = (b[i-1]+a[i-1])*2;
    }
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%I64d\n",a[n]+b[n]);
    }
    return 0;
}