//http://acm.hdu.edu.cn/showproblem.php?pid=2096
/*ÎÒÏ²»¶×öA+B*/
#include <stdio.h>
int main()
{
	//freopen("input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		__int64 a,b;
		scanf("%I64d %I64d",&a,&b);
		int c = (a % 100 + b % 100) % 100;
		printf("%d\n",c);
	}
	return 0;
}