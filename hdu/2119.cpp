//http://acm.hdu.edu.cn/showproblem.php?pid=2119

#include <cstdio>
#include <cstring>
#define RANGE 100
int n = 0,m = 0;
int visited[RANGE];
int linked[RANGE];
int graph[RANGE][RANGE];


bool AugmentPath(int left)
{
	for(int i = 0;i<m;++i)
	{
		if(!visited[i]&&graph[left][i])
		{
			visited[i] = 1;
			if((linked[i]==-1)||AugmentPath(linked[i]))
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
	freopen("input.txt","r",stdin);
	while(scanf("%d",&n),n)
	{
		scanf("%d",&m);
		memset(graph,0,sizeof(graph));
		memset(linked,-1,sizeof(linked));
		for(int i = 0;i<n;++i)
		{
			for(int j = 0;j<m;++j)
				scanf("%d",&graph[i][j]);
		}
		int sum = 0;
		for(int i = 0;i<n;++i)
		{
			memset(visited,0,sizeof(visited));
			if(AugmentPath(i))
				sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}