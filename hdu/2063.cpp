//http://acm.hdu.edu.cn/showproblem.php?pid=2063
/*
裸的二分匹配题目
*/
#include <stdio.h>
#include <string.h>
#define RANGE 510
int k,m,n;
int graph[RANGE][RANGE];
int linked[RANGE],visited[RANGE];

bool AugmentPath(int left)
{
	for(int i = 1;i <= n;++i)
	{
		if(!visited[i]&&graph[left][i])
		{
			visited[i] = 1;
			if((-1 == linked[i])||AugmentPath(linked[i]))
			{
				linked[i] = left;
				return true;
			}
		}
	}
	return false;
}


int main()
{
	while(scanf("%d",&k) != EOF)
	{
		if(0 == k)
			break;
		memset(graph,0,sizeof(graph));
		memset(linked,-1,sizeof(linked));
		scanf("%d %d",&m,&n);
		for(int i = 1;i <= k;++i)
		{
			int girl,boy;
			scanf("%d %d",&girl,&boy);
			graph[girl][boy] = 1;
		}
		int sum = 0;
		for(int i = 1;i <= m;++i)
		{
			memset(visited,0,sizeof(visited));
			if(AugmentPath(i))
				sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}