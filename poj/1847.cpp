/*
  single source shortest path
  dijkstra
 */
#include<cstdio>
#include<cstring>
using namespace std;

int MAX = 999999; // make it 9999999 will have wrong answer on C++
int mat[110][110];
// really weird
int dist[110];  // has to be global variable to accepted in G++
bool visited[110];  // has to be global variable to accepted in G++

int min(int a,int b)
{
    return a>b?b:a;
}


int dijkstra(int start,int end, int n)
{
    memset(dist,MAX,sizeof(dist));
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
	    if(!visited[j]&&min>dist[j])
	    {
		u = j;
		min = dist[j];
	    }
	}

	visited[u] = true;

	for(int j = 1;j<=n;++j)
	{
	    if(!visited[j]&&dist[j]>dist[u]+mat[u][j])
	    {
		dist[j] = dist[u] + mat[u][j];
	    }
	}
    }

    return dist[end];
}



int main()
{
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    memset(mat,MAX,sizeof(mat));
    for(int i = 1;i<=n;++i)
    {
	int k;
	scanf("%d",&k);
	for(int j = 1;j<=k;++j)
	{
	    int end;
	    scanf("%d",&end);
	    if(j==1)
	    {
		// the switch is pointing to the first one
		mat[i][end] = 0;
	    }
	    else
	    {
		mat[i][end] = 1;
	    }
	}
    }

    int result = dijkstra(a,b,n);

    printf("%d\n",result<MAX?result:-1);
    
    return 0;
}
