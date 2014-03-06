/*
  disjoint set
*/


#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

#define RANGE 1010

int p[RANGE],repair[RANGE];
int x[RANGE],y[RANGE];
vector<int> in_range[RANGE];

int find(int x)
{
    if(p[x]==x)
	return x;
    else
    {
	p[x] = find(p[x]);
	return p[x];
    }
}


double range(int i,int j)
{
    return sqrt((double)(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}


void compute_range(int n,int d)
{
    for(int i = 1;i<=n;++i)
    {
	for(int j = 1;j<=n;++j)
	{
	    if(range(i,j)<=d)
		in_range[i].push_back(j);
	}
    }
}



int main()
{
    int n,d;
    scanf("%d %d",&n,&d);
    for(int i = 1;i<=n;++i)
    {
	scanf("%d %d",&x[i],&y[i]);
    }
    compute_range(n,d);
    memset(repair,0,sizeof(repair));
    for(int i = 1;i<=n;++i)
    {
	p[i] = i;
    }


    char o;
    while(scanf("%c",&o)!=EOF)
    {
	int a,b;
	if(o=='O')
	{
	    scanf("%d",&a);
	    repair[a] = 1;
	    // add all the computer repaired in range d into the same set
	    for(int i = 0;i<in_range[a].size();++i)
	    {
		if(repair[in_range[a][i]])
		{
		    int u = find(in_range[a][i]);
		    int v = find(a);
		    if(u!=v)
		    {
			p[u] = v;
		    }
		}
	    }
	}
	else if(o=='S')
	{
	    scanf("%d %d",&a,&b);
	    int u = find(a);
	    int v = find(b);
	    if(u==v)
		printf("SUCCESS\n");
	    else
		printf("FAIL\n");
	}
    }


    return 0;
}
