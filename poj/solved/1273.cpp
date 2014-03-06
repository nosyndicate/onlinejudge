/*
  max-flow
 */
#include<cstdio>
#include<climits>
#include<cstring>
#include<queue>
using namespace std;

#define RANGE 205

int cap[RANGE][RANGE];
int flow[RANGE][RANGE];
int a[RANGE],p[RANGE];



int augment_path(int src,int sink, int m)
{
    queue<int> q;
    // a[i] is the minimal capacity from source to vertex i	
    memset(a,0,sizeof(a));

    a[src] = INT_MAX;
    q.push(src);
    while(!q.empty())  // search by bfs
    { 
	int u = q.front();
	q.pop(); // take the start element
	for(int v = 1;v<=m;++v)
	{
	    //m_r can used as visited array in bfs	
	    if(!a[v]&&cap[u][v]>flow[u][v]) 
	    {
		q.push(v);
		p[v] = u;
		a[v] = a[u]<cap[u][v]-flow[u][v]?a[u]:cap[u][v]-flow[u][v];
	    }
	}
    }
    
    return a[sink];
}



int max_flow(int m)
{
    int src = 1;
    int sink = m;
    int f = 0;

    while(true)
    {
	int pv = augment_path(src,sink,m);
	if(pv==0)
	    break;
	
	// go from sink to source to update the flow
	for(int u = sink;u!=src;u=p[u])
	{
	    flow[p[u]][u] += pv; // update flow
	    // flow could be negative, which indicate that edge is not in graph
	    flow[u][p[u]] -= pv; 
	}
	
	f += pv; // update the total flow
    }
    
    return f;
}



int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
	// initialize the graph
	memset(cap,0,sizeof(cap));
	memset(flow,0,sizeof(flow));
	for(int i = 0;i<n;++i)
	{
	    int s,e,c;
	    scanf("%d %d %d",&s,&e,&c);
	    cap[s][e]+=c; // we might have multiple edge
	}

	int f = max_flow(m);
	printf("%d\n",f);
    }
}







