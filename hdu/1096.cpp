//http://acm.hdu.edu.cn/showproblem.php?pid=1096
#include<stdio.h>
int main()
{
    int m,n,c,sum[1000] = { 0 };
    scanf("%d",&m);
    for(int i = 0;i<m;++i)
    {
        scanf("%d",&n);
        for(int j =0;j<n;j++)
        {
            scanf("%d",&c);
            sum[i]+=c;
        }
    }
    printf("%d\n",sum[0]);
    for(int i = 1;i<m;++i)
        printf("\n%d\n",sum[i]);
}
