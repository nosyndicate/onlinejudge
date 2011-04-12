//http://acm.hdu.edu.cn/showproblem.php?pid=1150

/*二分图最小顶点覆盖*/

#include<cstdio>
#include <cstring>
#define RANGE 110
int graph[RANGE][RANGE];
int visited[RANGE];
int linked[RANGE];
int n,m,k;


bool AugmentPath(int left)
{
	for(int i = 0;i < m;++i)
	{
		if(!visited[i]&&graph[left][i])
		{
			visited[i] = 1;
			if((linked[i]==-1)||(AugmentPath(linked[i])))
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
		scanf("%d %d",&m,&k);
		memset(graph,0,sizeof(graph));
		memset(linked,-1,sizeof(linked));
		for(int j = 0; j < k ;++j)
		{
			int i,left,right;
			scanf("%d %d %d",&i,&left,&right);
			if(left&&right)//tricky, the mode is 0 at the beginning, careful!
				graph[left][right] = 1;
		}
		int sum = 0;//the maximum bipartite matching, also the Least vertex cover
		for(int i = 0;i < n;++i)
		{
			memset(visited,0,sizeof(visited));
			if(AugmentPath(i))
				sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}