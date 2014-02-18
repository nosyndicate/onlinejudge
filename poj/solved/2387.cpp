/*
  single source shortest path
  dijkstra
 */
#include<cstdio>
#include<cstring>

int mat[1010][1010];

int min(int a,int b)
{
    if(a>b)
	return b;
    else 
	return a;
}


int dijkstra(int start, int end)
{
    int n = end;
    bool visited[1010];
    int dist[1010];

    memset(dist,0,sizeof(dist));

    for(int i = 1;i<=n;++i)
    {
	if(start==i)
	{
	    dist[i] = 0;
	}
	else
	{
	    dist[i] = 99999999;
	    visited[i] = false;
	}
	
    }
    
    for(int i = 1;i<=n;++i) // n-1 times
    {
	int u,min = 99999999;
	for(int j = 1;j<=n;++j)
	{
	    if(visited[j]==false&&dist[j]<min)
	    {
		min = dist[j];
		u = j;
	    }
	}
	visited[u] = true;
	for(int j = 1;j<=n;++j)//relaxation for each edge
	{
	    if(visited[j]==false&&min+mat[u][j]<dist[j])
	    {
		dist[j] = min + mat[u][j];
	    }
	}

    }

    return dist[end];

}


int main()
{
    int e,v;
    for(int i = 0;i<1010;++i)
    {
	for(int j = 0;j<1010;++j)
	{
	    mat[i][j] = 99999999;
	}
    }
    scanf("%d %d",&e,&v);
    for(int i = 0;i<e;++i)
    {
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	// bidirectio graph and also we could have multiple edges between each
	// vetice
	mat[a][b] = mat[b][a] = min(c,mat[a][b]); 
    }


    printf("%d\n",dijkstra(1,v));
    return 0;
}
