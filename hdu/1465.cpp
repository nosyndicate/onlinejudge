//http://acm.hdu.edu.cn/showproblem.php?pid=1465
#include <stdio.h>
int main()
{
	__int64 n,a[21];
	a[1] = 0;
	a[2] = 1;
	for(int i = 3;i<21;++i)
		a[i] = (i-1)*(a[i-1]+a[i-2]);
	while(scanf("%d",&n)!=EOF)
	{
		printf("%I64d\n",a[n]);
	}
}

/*
有N封信的时候,前面N-1封信可以有N-1或者N-2封错装
前者，对于每种错装,可从N-1封信中任意取一封和第N封错装,故=F(N-1)*(N-1)
后者简单,只能是没装错的那封和第N封交换信封,没装错的那封可以是前面N-1封中的任意一个,故=F(N-2)*(N-1)
*/