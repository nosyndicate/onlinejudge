//http://acm.hdu.edu.cn/showproblem.php?pid=1087
#include <stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		int a[1000],b[1000];
		for(int i = 0;i<n;++i)
			scanf("%d",&a[i]);
		b[0] = a[0];
		int ret = a[0];
		for(int i = 1;i<n;++i)
		{
			int max = 0;
			for(int j = i-1;j>=0;--j)
			{
				if(a[j]>=a[i])
					continue;
				if(b[j]>max)
					max = b[j];
			}
			b[i] = a[i]+max;
			if(ret<b[i])
				ret = b[i];
		}
		printf("%d\n",ret);
	}
	return 0;
}