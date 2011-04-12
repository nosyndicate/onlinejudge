//http://acm.hdu.edu.cn/showproblem.php?pid=2081
#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		char a[12];
		scanf("%s",a);
		printf("6%s\n",a+6);
	}
	return 0;
}