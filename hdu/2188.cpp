//http://acm.hdu.edu.cn/showproblem.php?pid=2188
#include <stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		while(n>m)
			n-=(m+1);
		if(1<=n&&n<=m)
			printf("Grass\n");
		else
			printf("Rabbit\n");
	}
	return 0;
}