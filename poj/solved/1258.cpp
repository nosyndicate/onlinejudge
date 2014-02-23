
/*
  Two optimization technique could be used to disjoint set find method,
  
  One is called union by rank, which simply let the root of the  tree with 
  smaller height (rank) point to the tree with greater height.

  Another is called path compression. By find a certain element, let the all 
  the elements on the searching path point to the root.

  Two method can be combined.
*/


#include<cstdio>
#include<algorithm>
using namespace std;


int set[10010];  // we have 100 node, so we can at most have 10000 edge
int u[10010],w[10010],v[10010],r[10010];
int n;

int cmp(const int i, const int j)
{
    return w[i]<w[j];
}


int find(int x)
{
    if(set[x]==x) // x is the root
	return x;
    else  // otherwise find its parent's tree's root 
    {
	set[x] = find(set[x]); // point the node to the root
	return set[x];
    }
}

int kruskal(int m)    
{
    int ans = 0; // weight of the total tree
    // initialize the disjoint set
    for(int i = 1;i<=m;++i)
	set[i] = i;

    for(int i = 1;i<=m;++i)
	r[i] = i;

    sort(r, r+m, cmp); // sort by the weight, see cmp

    for(int i = 1;i<=m;++i)
    {
	int e = r[i];
	int x = find(u[e]);
	int y = find(v[e]);
	
	if(x!=y)
	{
	    ans+=w[e];
	    set[x] = y;
	}
    }
    return ans;
}



int main()
{
    while(scanf("%d",&n)!=EOF)
    {
	int k = 1;
	for(int i = 1;i<=n;++i)
	{
	    for(int j = 1;j<=n;++j)
	    {
		u[k] = i;
		v[k] = j;
		scanf("%d",&w[k]);
		k++;
	    }
	}

	printf("%d\n",kruskal(n*n));
    }
    return 0;
}
