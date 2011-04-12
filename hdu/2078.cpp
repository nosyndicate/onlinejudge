//http://acm.hdu.edu.cn/showproblem.php?pid=2078

/*这题的m有什么存在的必要么？*/
#include <cstdio>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,min = 100;
		scanf("%d %d",&n,&m);
		while(n--)
		{
			int a;
			scanf("%d",&a);
			if(a < min)
				min = a;
		}
		printf("%d\n",(100-min)*(100-min));
	}
}