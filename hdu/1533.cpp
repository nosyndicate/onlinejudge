//http://acm.hdu.edu.cn/showproblem.php?pid=1533
/*km algorithm about bipartite graph, writing this code is so tired*/
#include <cstdio>
#include <cstring>
#include <cmath>
#define RANGE 105
#define INF 0x7f7f7f7f
struct loc
{
	int x,y;
};
loc man[RANGE],house[RANGE];
int graph[RANGE][RANGE];
int visitx[RANGE],visity[RANGE],slack[RANGE],linked[RANGE],lx[RANGE],ly[RANGE];
int n,m;

int min(int a,int b){return a>b?b:a;}

bool AugmentPath(int left,int range)
{
	visitx[left] = 1;
	for(int i = 0;i<range;++i)
	{
		if(!visity[i]&&lx[left]+ly[i]==graph[left][i])
		{
			visity[i] = 1;
			if(linked[i]==-1||AugmentPath(linked[i],range))
			{
				linked[i] = left;
				return true;
			}
		}
		else if(lx[left]+ly[i]>graph[left][i])
		{
			slack[i] = min(slack[i],lx[left]+ly[i]-graph[left][i]);
		}
	}
	return false;
}


int Km(int range)
{
	memset(linked,-1,sizeof(linked));
	for(int i = 0;i<range;++i)
	{
		while(true)
		{
			memset(visitx,0,sizeof(visitx));
			memset(visity,0,sizeof(visity));
			memset(slack,INF,sizeof(slack));
			if(AugmentPath(i,range))//find the augment path for the node i
				break;
			int d = INF;
			for(int i = 0;i<range;++i)// for every y node which has not been visited, looking for the smallest slack value
			{
				if(!visity[i])
					if(d>slack[i])
						d = slack[i];
			}
			for(int i = 0;i<range;++i)//amend the value of lx and ly
			{
				if(visitx[i])
					lx[i]-=d;
				if(visity[i])
					ly[i]+=d;
				else
					slack[i]-=d;
			}
		}
	}
	int sum = 0;
	for(int i = 0;i<range;++i)
		sum+=graph[linked[i]][i];
	return sum;
}


int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%d %d",&n,&m),m+n)
	{
		
		memset(lx,-INF,sizeof(lx));
		memset(ly,0,sizeof(ly));
		memset(graph,0,sizeof(graph));
		int mnt = 0,hnt = 0;
		for(int i = 0;i<n;++i)
		{
			getchar();
			for(int j = 0;j<m;++j)
			{
				char temp;
				scanf("%c",&temp);
				if(temp=='m')
				{
					man[mnt].x = i;man[mnt++].y = j;
				}
				else if(temp=='H')
				{
					house[hnt].x = i;house[hnt++].y = j;
				}
			}
		}
		for(int i = 0;i<mnt;++i)
		{
			for(int j = 0;j<hnt;++j)
			{
				graph[i][j] = -(abs(man[i].x-house[j].x)+abs(man[i].y-house[j].y));
				if(graph[i][j] > lx[i])
					lx[i] = graph[i][j];
			}
		}
		int sum = Km(mnt);
		printf("%d\n",-sum);
	}
	return 0;
}