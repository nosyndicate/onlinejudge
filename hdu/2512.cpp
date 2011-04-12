//http://acm.hdu.edu.cn/showproblem.php?pid=2512
//a[i][j],i张卡放到j本书里的方法
#include <stdio.h>
__int64 a[2001][2001];
int main()
{
	a[2][2] = 1;
	for(int i = 1;i<2001;++i)
		a[i][1] = 1;
	for(int i = 3;i<2001;++i)
	{
		for(int j = 2;j<2001;++j)
		{
			a[i][j] = j*a[i-1][j] + a[i-1][j-1];
			if(a[i][j]>1000)
				a[i][j]%=1000;
		}
	}
	int t,n,sum = 0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int j = 1;j<=n;++j)
		{
			sum+=a[n][j];
			if(sum>1000)
				sum%=1000;
		}
		printf("%d\n",sum);
		sum = 0;
	}
	return 0;
}