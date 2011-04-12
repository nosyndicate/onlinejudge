//http://acm.hdu.edu.cn/showproblem.php?pid=2049
#include <stdio.h>
int main()
{
	int t,n,m;
	__int64 a[21];
	a[1] = 0,a[2] = 1;
	for(int i = 3;i<21;++i)
		a[i] = (i-1)*(a[i-1]+a[i-2]);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		__int64 upper = 1,lower1 = 1,lower2 = 1;
		for(int i = 1;i<=n;++i)
			upper*=i;
		for(int i = 1;i<=n-m;++i)
			lower1*=i;
		for(int i = 1;i<=m;++i)
			lower2*=i;
		__int64 ret = upper/(lower1*lower2)*a[m];
		printf("%I64d\n",ret);
	}
	return 0;
}