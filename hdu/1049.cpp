//http://acm.hdu.edu.cn/showproblem.php?pid=1049
#include <stdio.h>

int main()
{
	int n,u,d,time;
	scanf("%d %d %d",&n,&u,&d);
	while(n!=0)
	{
		int t = n-u;
		int a = t%(u-d);
		if(a==0)
			time = t/(u-d);
		else
			time = 1+(t-a)/(u-d);
		(time*=2)++;
		printf("%d\n",time);
		scanf("%d %d %d",&n,&u,&d);
	}
}