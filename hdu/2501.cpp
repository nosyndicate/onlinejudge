//http://acm.hdu.edu.cn/showproblem.php?pid=2501
#include <stdio.h>
int main()
{
	__int64 a[31];
	a[1] = 1;
	a[2] = 3;
	for (int i = 3;i<31;++i)
	{
		a[i] = a[i-1]+2*a[i-2];
	}
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int t;
		scanf("%d",&t);
		printf("%I64d\n",a[t]);
	}
	return 0;
}