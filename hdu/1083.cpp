//http://acm.hdu.edu.cn/showproblem.php?pid=1083
/*
二分图匹配，匈牙利算法
*/
#include<stdio.h>
#include <string.h>
#define COURSE 110
#define STUDENT 310
int graph[COURSE][STUDENT];
int visited[STUDENT];
int linked[STUDENT];
int p,n;


bool AugmentPath(int left)
{
	for(int right = 1;right <= n;++right)
	{
		if(graph[left][right]&&!visited[right])
		{
			visited[right] = 1;
			int linkedLeft = linked[right];
			linked[right] = left;
			if((linkedLeft == -1)||AugmentPath(linkedLeft))
				return true;
			linked[right] = linkedLeft;
		}
	}
	return false;
}

int main()
{
	freopen("input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&p,&n);
		int sum = 0;
		memset(graph,0,sizeof(graph));
		memset(linked,-1,sizeof(linked));
		for(int i = 1;i <= p;i++)
		{
			int cnt;
			scanf("%d",&cnt);
			for(int j = 1;j <= cnt;++j)
			{
				int student;
				scanf("%d",&student);
				graph[i][student] = 1;
			}
		}
		for(int i = 1;i <= p;++i)
		{
			memset(visited,0,sizeof(visited));
			if(AugmentPath(i))
				sum++;
		}
		
		if(sum == p)// if the course number could match the link number
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}