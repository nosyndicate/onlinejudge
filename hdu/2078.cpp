//http://acm.hdu.edu.cn/showproblem.php?pid=2078

/*�����m��ʲô���ڵı�Ҫô��*/
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