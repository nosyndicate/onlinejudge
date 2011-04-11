//http://acm.hdu.edu.cn/showproblem.php?pid=1068
/*题目都没有怎么读懂，不过好像是裸的二分图最大独立集*/
#include<cstdio>
#include<cstring>
#define RANGE 505
int graph[RANGE][RANGE];
int visited[RANGE];
int linked[RANGE];
int students;
bool AugmentPath(int left)
{
	for(int i = 0;i < students;++i)
	{
		if(!visited[i]&&graph[left][i])
		{
			visited[i] = 1;
			if((linked[i] == -1)||(AugmentPath(linked[i])))
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
	while(scanf("%d",&students) != EOF)
	{
		int sum = 0;
		memset(graph,0,sizeof(graph));
		memset(linked,-1,sizeof(linked));
		for(int i = 0; i < students;++i)
		{
			int left,rightNum;
			scanf("%d: (%d)",&left,&rightNum);
			for(int j = 0;j<rightNum;++j)
			{
				int right;
				scanf("%d",&right);
				graph[left][right] = 1;
			}
		}
		for(int i = 0; i < students;++i)
		{
			memset(visited,0,sizeof(visited));
			if(AugmentPath(i))
				sum++;
		}
		printf("%d\n",students-sum/2);
	}
	return 0;
}