/*
  relationship disjoint set
 */

#include<cstdio>
using namespace std;
#define RANGE 100010

int p[RANGE];//parent array
int r[RANGE];//relationship array
             //0 stand for same gang
             //1 stand for differnt

void initialization(int n)
{
    for(int i = 1;i<=n;++i)
    {
	p[i] = i;
	r[i] = 0;
    }
}


int find(int x)
{
    if(p[x]==x)
	return x;
    else
    {
	int temp = p[x];
	p[x] = find(p[x]);
	r[x] = (r[x]+r[temp])%2;
	return p[x];
    }
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
	int n,m;
	scanf("%d %d",&n,&m);
	initialization(n);
	for(int i = 0;i<m;++i)
	{
	    char c[10];
	    int a,b;
	    scanf("%s%d%d",c,&a,&b);
	    int x = find(a);
	    int y = find(b);
	
	    if(c[0]=='A')
	    {
		if(x!=y)// not in the same tree
		{
		    printf("Not sure yet.\n");
		}
		else if(x==y)
		{
		    if(r[a]==r[b])
		    {
			printf("In the same gang.\n");
		    }
		    else
		    {
			printf("In different gangs.\n");
		    }
		}
	    }
	    else if(c[0]=='D')
	    {
		p[y] = x; // connect, x's parent is y
		r[y] = (r[a]+1+r[b])%2; // belong to different gang
	    }
	}
    }
    return 0;
}
