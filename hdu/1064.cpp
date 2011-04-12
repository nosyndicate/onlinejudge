//http://acm.hdu.edu.cn/showproblem.php?pid=1064
#include <stdio.h>
int main()
{
	double n,s = 0;
	while(scanf("%lf",&n)!=EOF)
		s+=n;
	printf("$%.2lf\n",s/12);
	return 0;
}