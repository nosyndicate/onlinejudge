//http://acm.hdu.edu.cn/showproblem.php?pid=2560
/*just c language*/
#include <stdio.h>
int main()
{
	freopen("input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,sum = 0;
		scanf("%d %d",&n,&m);
		for(int i = 0; i < n;++i)
		{
			for(int j = 0; j < m;++j)
			{
				int temp;
				scanf("%d",&temp);
				if(1 == temp)
					sum++;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}