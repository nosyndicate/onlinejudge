//http://acm.hdu.edu.cn/showproblem.php?pid=2544
/*shortest path, dijkstra.*/
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define N 101
#define M 10000
#define INF 0x7f7f7f7f
int graph[N][N],visited[N],dist[N];
int n,m;

struct Node
{
	Node(int _n,int _l):n(_n),l(_l){}
	int n,l;
	bool operator < (const Node& rightValue) const
	{
		return this->l > rightValue.l; 
	}
};


void Dijkstra(int start)
{
	priority_queue<Node> heap;
	memset(dist,INF,sizeof(dist));
	memset(visited,0,sizeof(visited));
	dist[start] = 0;
	visited[start] = 1;
	int visit = 1;
	for(int i = 1;i<=n;++i)
	{
		graph[i][i] = 0;
		if(i!=start&&graph[start][i]!=INF)
		{
			Node node(i,graph[start][i]);
			heap.push(node);
		}
	}

	while(visit<n)
	{
		Node node(0,0);
		if(!heap.empty())
			node = heap.top();
		heap.pop();
		
		if(visited[node.n])
			continue;
		visited[node.n] = 1;
		dist[node.n] = node.l;
		visit++;

		for(int i = 1;i<=n;++i)
		{
			if(!visited[i]&&dist[i]>graph[node.n][i]+dist[node.n])
			{
				dist[i] = graph[node.n][i] + dist[node.n];
				Node NewNode(i,dist[i]);
				heap.push(NewNode);
			}
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

		Dijkstra(1);
		printf("%d\n",dist[n]);
	}
	return 0;
}