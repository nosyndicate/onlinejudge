//http://acm.hdu.edu.cn/showproblem.php?pid=2101
/*C”Ô—‘Ã‚ƒø*/
#include <stdio.h>

int main()
{
	//freopen("input.txt","r",stdin);
	__int64 a,b;
	while(scanf("%I64d %I64d",&a,&b) != EOF)
	{
		if((a+b)%86 == 0)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}