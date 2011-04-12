//http://acm.hdu.edu.cn/showproblem.php?pid=1003

#include <stdio.h>
int sequence[100001];
int maxnum = -1001;
int begin = 0,end = 0,temp = 0,result = 0;

int main()
{
	int t,n;
	scanf("%d",&t);
	for(int i = 0;i<t;++i)
	{
		scanf("%d",&n);
		for(int j = 0;j<n;++j)
		{
			scanf("%d",&sequence[j]);
		}
		for(int j = 0;j<n;++j)
		{
			result+=sequence[j];
			if(result>maxnum)
			{
				maxnum = result;
				begin = temp;
				end = j;
			}
			if(result<0)
			{
				result = 0;
				temp = j+1;
			}
		}
		printf("Case %d:\n%d %d %d\n",i+1,maxnum,begin+1,end+1);
		if(i!=t-1)
			printf("\n");	
		maxnum = -1001,begin = 0,end = 0,temp = 0,result = 0;
	}
}