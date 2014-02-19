/*
  single source shortest path
  dijkstra
 */

#include<cstdio>
#include<cstring>

using namespace std;

int MAX = 9999999;
int mat[1010][1010]; // graph for return from the party
int r_mat[1010][1010]; // graph for go to the party
int dist[1010]; // distance for return from the party
int r_dist[1010]; // distance for go to the party


int min(int a,int b)
{
    if(a>b)
	return b;
    else
	return a;
}


int dijkstra(int start, int n, int dist[],int mat[][1010])
{
    bool visited[1010];
    memset(visited,false,sizeof(visited));
    
    for(int i = 1;i<=n;++i)
    {
	dist[i] = mat[start][i];
    }
    visited[start] = true;

    for(int i = 2;i<=n;++i)
    {
	int u,min = MAX;
	for(int j = 1;j<=n;++j)
	{
	    if(!visited[j]&&dist[j]<min)
	    {
		u = j;
		min = dist[j];
	    }
	}
	visited[u] = true;

	for(int j = 1;j<=n;++j)
	{
	    if(!visited[j]&&mat[u][j]+dist[u]<dist[j])
	    {
		dist[j] = dist[u]+mat[u][j];
	    }
	}
    }

}


int main()
{
    int n,m,x;
    scanf("%d %d %d",&n,&m,&x);

    // initialize graph matrix
    memset(mat,MAX,sizeof(mat));
    memset(r_mat,MAX,sizeof(r_mat));
    memset(dist,MAX,sizeof(dist));
    memset(r_dist,MAX,sizeof(r_dist));
    
    for(int i = 0;i<m;++i)
    {
	int a,b,t;
	scanf("%d %d %d",&a,&b,&t);
	mat[a][b] = min(t,mat[a][b]);
	r_mat[b][a] = min(t,r_mat[b][a]);
    }

    
    dijkstra(x,n,r_dist,r_mat);
    dijkstra(x,n,dist,mat);
    
    dist[x] = r_dist[x] = 0; // we don't count the party farm

    int max = -1;

    for(int i = 1;i<=n;++i)
    {
	if(r_dist[i]+dist[i]>max)
	    max = r_dist[i]+dist[i];
    }

    printf("%d\n",max);

}
