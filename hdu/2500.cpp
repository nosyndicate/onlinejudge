//http://acm.hdu.edu.cn/showproblem.php?pid=2500
#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int t;
        scanf("%d",&t);
        for(int i = 0;i<3*t;++i)
        {
            for(int j = 0;j<t;++j)
                printf("%s","HDU");
            printf("\n");
        }            
    }
    return 0;
}