//http://acm.hdu.edu.cn/showproblem.php?pid=1050
#include <stdio.h>
int main()
{
	int t,n,s,e;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int p[200] = {0};
		for(int i = 0;i<n;++i)
		{
			scanf("%d %d",&s,&e);
			if(s>e)
			{
				s^=e;
				e^=s;
				s^=e;
			}
			s = (s-1)/2;
			e = (e-1)/2;
			for(int i = s;i<=e;++i)
				p[i]++;
		}
		int min = -1;
		for(int i = 0;i<200;++i)
			if(min<p[i])
				min = p[i];
		printf("%d\n",min*10);
	}
	return 0;
}