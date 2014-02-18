#include<cstdio>
#include<cstring>
using namespace std;

int matrix[1010][1010];


int min(int a,int b)
{
    if(a>b)
	return b;
    else
	return a;
}

int dijkstra(int start,int n)
{
    int end = n;
    int dist[1010]; // use dist for consistent
    bool visited[1010];
    for(int i = 0;i<1010;++i)
    {
	dist[i] = 0;
	visited[i] = false;
    }
    for(int i = 1;i<=n;++i)
    {
	dist[i] = matrix[start][i];
    }
    visited[start] = true;
    for(int i = 1;i<=n;++i)
    {
	int u,max = -100;
	for(int j = 1;j<=n;++j)
	{
	    if(!visited[j]&&dist[j]>max)
	    {
		max = dist[j];
		u = j;
	    }
	}

	visited[u] = true;
	for(int j = 1;j<=n;++j)
	{
	    if(!visited[j]&&matrix[u][j]>0)
	    {
		//relaxation
		if(dist[j]<min(dist[u],matrix[u][j]))
		    dist[j] = min(dist[u],matrix[u][j]);
	    }
	}
    }
    return dist[n];

}


int main()
{
    int t;
    scanf("%d",&t);    
    for(int k = 1;k<=t;++k)
    {
	memset(matrix,0,sizeof(matrix));

	int m,n;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<m;++i)
	{
	    int s,e,w;
	    scanf("%d %d %d",&s,&e,&w);
	    matrix[s][e] = matrix[e][s] = w;
	}

	int result = dijkstra(1,n);

	printf("Scenario #%d:\n%d\n\n",k,result);
    }
    return 0;
}
