//http://acm.hdu.edu.cn/showproblem.php?pid=1874
/*still shortest path, use binary heap in dijkstra
有可能有重边，另外需要主要heap为空的情况*/

#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define INF 0x7f7f7f7f
#define VERTEX 201
int n,m;
int graph[VERTEX][VERTEX],visited[VERTEX],dist[VERTEX];

struct Node
{
	Node(int _n,int _l):n(_n),l(_l){}
	int n,l;
	bool operator < (const Node& rightValue) const
	{
		return l > rightValue.l;
	}
};


void Dijkstra(int start)
{
	priority_queue<Node> heap;
	memset(visited,0,sizeof(visited));
	memset(dist,INF,sizeof(dist));
	int add = 0;
	dist[start] = 0;
	
	Node node(start,dist[start]);
	heap.push(node);
	while(add<n)
	{
		Node node(0,0);
		if(!heap.empty())
		{
			node = heap.top();
			heap.pop();
		}
		else
			break;

		if(visited[node.n])
			continue;
		visited[node.n] = 1;
		dist[node.n] = node.l;
		add++;
		for(int i = 0;i<n;++i)
		{
			if(!visited[i]&&dist[i]>dist[node.n]+graph[node.n][i])
			{
				dist[i] = dist[node.n] + graph[node.n][i];
				Node NewNode(i,dist[i]);
				heap.push(NewNode);
			}
		}
	}

}


int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		memset(graph,INF,sizeof(graph));
		for(int i = 0;i<n;++i)
			graph[i][i] = 0;
		for(int i = 0;i<m;++i)
		{
			int a,b,x;
			scanf("%d %d %d",&a,&b,&x);
			if(graph[a][b]>x)
			{	
				graph[a][b] = x;
				graph[b][a] = x;
			}
		}
		int s,t;
		scanf("%d %d",&s,&t);
		Dijkstra(s);
		printf("%d\n",dist[t]==INF?-1:dist[t]);
	}
	return 0;
}