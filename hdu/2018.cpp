//http://acm.hdu.edu.cn/showproblem.php?pid=2018
#include <stdio.h>
int main()
{
    int n;
    int a[56] = {0};
    a[1] = 1;
    for(int i = 2;i<56;++i)
    {
        for(int j = i-1;j>=1;--j)
        {
            if(i-j>=3||j==1)
                a[i]+=a[j];
        }
    }
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        int sum = 0;
        for(int i = 1;i<=n;++i)
            sum+=a[i];
        printf("%d\n",sum);
    }
    return 0;
}