//http://acm.hdu.edu.cn/showproblem.php?pid=2085
#include<stdio.h>
int main()
{
	__int64 a[34],b[34];
	a[0] = 0,b[0] = 1;
	for(int i = 1;i<34;++i)
	{
		a[i] = a[i-1]+b[i-1];
		b[i] = 2*a[i-1]+3*b[i-1];
	}
	int n;
	while(scanf("%d",&n)!=EOF&&n!=-1)
	{
		printf("%I64d, %I64d\n",b[n],a[n]);
	}
	return 0;
}