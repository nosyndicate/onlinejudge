//http://acm.hdu.edu.cn/showproblem.php?pid=2044
#include <stdio.h>

long long f(int n)
{
    long long f1 = 1,f2 = 2,ret = 0;
    if(n<=2)
    {
        return n;
    }
    for(int i = 2;i<n;++i)
    {
        ret = f1 + f2;
        f1 = f2;
        f2 = ret;
    }
    return ret;
}



int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        long long ret = f(b-a);
        printf("%I64d\n",ret);//输出用%I64d,切记切记
    }
}
