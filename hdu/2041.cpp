//http://acm.hdu.edu.cn/showproblem.php?pid=2041
#include <stdio.h>
int main()
{
	__int64 a[41];
	a[1] = 1,a[2] = 2;
	for(int i = 3;i<41;++i)
		a[i] = a[i-1]+a[i-2];
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%I64d\n",a[n-1]);
	}
	return 0;
}


