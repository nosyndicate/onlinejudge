/*
  dijkstra
  single source shortest path
*/
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;


#define MAX 99

struct Vertex
{
    int x;
    int y;
};

int maze[5][5];
int label[5][5];
Vertex vertice[25];
int graph[25][25];
int parent[25];


void dijkstra(int start)
{
    int dist[25];
    bool visited[25];
    memset(dist,MAX,sizeof(dist));
    memset(visited,0,sizeof(visited));
    memset(parent,-1,sizeof(parent));
    for(int i = 0;i<25;++i)
    {
	dist[i] = graph[start][i];
	if(dist[i]<MAX)
	{
	    parent[i] = start;
	}
    }
    visited[start] = true;
   
    for(int i = 1;i<25;++i)
    {
	int min = MAX,u = -1;
	for(int j = 0;j<25;++j)
	{
	    if(!visited[j]&&dist[j]<min)
	    {
		min = dist[j];
		u = j;
	    }
	}
	visited[u] = true;
	for(int j = 0;j<25;++j)
	{
	    if(!visited[j]&&dist[u]+graph[u][j]<dist[j])
	    {
		dist[j] = dist[u]+graph[u][j];
		parent[j] = u;
	    }
	}
    }


}




int main()
{
    int k = 0;
    // read in maze
    for(int i = 0;i<5;++i)
    {
	for(int j = 0;j<5;++j)
	{
	    scanf("%d",&maze[i][j]);
	    label[i][j] = k;
	    vertice[k].x = i;
	    vertice[k].y = j;
	    k++;
	}
    }

    memset(graph,99,sizeof(graph));
    // construct the graph
    for(int i = 0;i<25;++i)
    {
	int x = vertice[i].x;
	int y = vertice[i].y;
	if(maze[x][y]==0)
	{
	    //every node has four direct connection
	    if(x-1>=0&&maze[x-1][y]!=1) // upper node
	    {
		graph[i][label[x-1][y]] = 1;
	    }
	    if(y-1>=0&&maze[x][y-1]!=1) //left node
	    {
		graph[i][label[x][y-1]] = 1;
	    }
	    if(x+1<=4&&maze[x+1][y]!=1) // lower node
	    {
		graph[i][label[x+1][y]] = 1;
	    }
	    if(y+1<=4&&maze[x][y+1]!=1) // right node
	    {
		graph[i][label[x][y+1]] = 1;
	    }
	}
    }

    dijkstra(0);

    // trace back to the source
    stack<int> Stack;
    int p = 24;
    while(p!=-1)
    {
	Stack.push(p);
	p = parent[p];
    }

    while(!Stack.empty())
    {
	int e = Stack.top();
	Stack.pop();
	printf("(%d, %d)\n",vertice[e].x,vertice[e].y);
    }
    
    return 0;
}
