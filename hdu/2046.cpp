//http://acm.hdu.edu.cn/showproblem.php?pid=2046
#include <stdio.h>
int main()
{
    int n;
    long long ret,f1 = 1,f2 = 2;
    while(scanf("%d",&n)!=EOF)
    {
        if(n<=2)
        {
            printf("%d\n",n);
            continue;
        }
        for(int i = 2;i<n;++i)
        {
            ret = f1 + f2;
            f1 = f2;
            f2 = ret;
        }
        printf("%I64d\n",ret);
        f1 = 1,f2 = 2;
    }
    return 0;
}