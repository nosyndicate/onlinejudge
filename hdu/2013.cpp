//http://acm.hdu.edu.cn/showproblem.php?pid=2013
#include <stdio.h>

int main()
{
    int n,sum;
    while(scanf("%d",&n)!=EOF)
    {
        sum = 1;
        for(int i =0 ;i<n-1;++i)
        {
            sum = (sum+1)*2;
        }
        printf("%d\n",sum);
    }
}