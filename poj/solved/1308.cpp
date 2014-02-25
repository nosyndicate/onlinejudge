/*
  disjoint set
*/


#include<cstdio>
#include<cstring>

using namespace std;

#define MAX_N 10000
int set[MAX_N];
int degree[MAX_N];
bool flag[MAX_N];

void initialize_set()
{
    for(int i = 1;i<MAX_N;++i)
    {
	set[i] = i;
    }
    memset(degree,0,sizeof(degree));
    memset(flag,0,sizeof(flag));
}


int find(int x)
{
    if(set[x]==x)
	return x;
    else
    {
	set[x] = find(set[x]);
	return set[x];
    }
}


bool scan() // still have to check the degree and forest
{
    for(int i = 0;i<MAX_N;++i)
    {
	if(degree[i]>1)
	{
	    return false;
	}
    }
    int root = -1;
    for(int i = 0;i<MAX_N;++i) // check the forestc
    {
	if(flag[i])
	{
	    if(root==-1)
		root = find(i);
	    else
	    {
		if(root!=find(i))
		    return false;
	    }
	}
	    
    }

    return true;
}




int main()
{
    int u,v,k = 1;
    bool tree = true;
 
 
    while(true)
    {
	initialize_set();
	tree = true;
	while(true)
	{
	    scanf("%d %d",&u,&v);
	    if(u==-1&&v==-1)
		break;
	    
	    if(u==0&&v==0)
		break;

	    flag[u] = flag[v] = true;

	    int f = find(u); int s = find(v);
	    if(f==s)
		tree = false;
	    else
	    {
		set[v] = u;
		degree[v]++;
	    }

	}

	if(u==-1&&v==-1)
	    break;

	if(tree)
	{
	    if(scan())
		printf("Case %d is a tree.\n",k);
	    else
		printf("Case %d is not a tree.\n",k);
	}
	else
	    printf("Case %d is not a tree.\n",k);

	k++;
    }
    return 0;
}
