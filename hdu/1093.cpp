//http://acm.hdu.edu.cn/showproblem.php?pid=1093
#include <stdio.h>
int main()
{
	int N,M,a,sum = 0;
	scanf("%d",&N);
	for(int j = 0;j<N;++j)
	{
		scanf("%d",&M);
		for(int i = 0;i<M;++i)
		{
			scanf("%d",&a);
			sum+=a;
		}
		printf("%d\n",sum);
		sum = 0;
	}
}