//http://acm.hdu.edu.cn/showproblem.php?pid=2544
/*shortest path, dijkstra.*/
#include<cstdio>
#include<cstring>
#define N 101
#define M 10000
#define INF 0x7f7f7f7f
int graph[N][N],visited[N],dist[N];
int n,m;


void Dijkstra()
{
	memset(visited,0,sizeof(visited));
	dist[1] = 0;
	visited[1] = 1;
	for(int i = 2;i<=n;++i)
		dist[i] = graph[1][i];
	
	int added = 1;
	while(added < n)
	{
		int length = INF;
		int node = -1;
		for(int j = 1;j<=n;++j)
		{
			if(!visited[j]&&dist[j]<length)
			{
				node = j;
				length = dist[j];
			}
		}

		visited[node] = 1;
		added++;
		for(int j = 1;j<=n;++j)
		{
			if(!visited[j]&&dist[node]+graph[node][j]<dist[j])
				dist[j] = dist[node] + graph[node][j];
		}
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%d %d",&n,&m),m+n)
	{
		memset(graph,INF,sizeof(graph));
		for(int i = 1;i<=m;++i)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			graph[a][b] = c;
			graph[b][a] = c;
		}

		Dijkstra();
		printf("%d\n",dist[n]);
	}
	return 0;
}