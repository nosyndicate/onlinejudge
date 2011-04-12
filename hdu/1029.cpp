//http://acm.hdu.edu.cn/showproblem.php?pid=1029
#include <stdio.h>
int main()
{
	int n,num,count;
	bool recount = true;
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			int t;
			getchar();
			scanf("%d",&t);
			if(recount==true)
			{
				num = t;
				count = 1;
				recount = false;
				continue;
			}
			if(t==num)
				count++;
			else
				count--;
			if(count==0)
				recount = true;
		}
		printf("%d\n",num);
		recount = true;
	}
	return 0;
}