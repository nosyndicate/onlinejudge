//http://acm.hdu.edu.cn/showproblem.php?pid=1092
#include <stdio.h>
int main()
{
    int N,a,sum = 0;
    while(scanf("%d",&N)&&N!=0)
    {
		for(int i = 0;i<N;++i)
		{
			scanf("%d",&a);
			sum+=a;
		}
		printf("%d\n",sum);
		sum = 0;
    }
}