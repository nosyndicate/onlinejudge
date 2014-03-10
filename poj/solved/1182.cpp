/*
  disjoint set
  use an array to record the relation to the father
*/
#include<cstdio>


using namespace std;

int set[50005];
int rel[50005]; //relation to the father node, 0 for same kind
                //1 for eat father node, 2 for eaten by father node

int find(int x)
{
    if(set[x]==x) // if x is root
	return x;
    //every node update its relationship based upon the relation with its parent
    else
    { 
	int temp = set[x]; // record the parent node
	set[x] = find(set[x]); // reset the parent node
	rel[x] = (rel[x]+rel[temp])%3;
	// attention: rel[x] is already the relation to root node
	return set[x];
    }
}

int main()
{
    int n,k,ans = 0;
    scanf("%d %d",&n,&k);

    // initialize the set
    for(int i = 1;i<=n;++i)
    {
	set[i] = i;
	rel[i] = 0;
    }

    for(int i = 0;i<k;++i)
    {
	int d,x,y;
	scanf("%d %d %d",&d,&x,&y);
	if(x>n||y>n) // x or y greater than n
	{
	    ans++;
	}
	else if(d==2&&x==y) // x eats x
	{
	    ans++;
	}
	else
	{
	    int p = find(x);  // p is the root and father of x now
	    int q = find(y);  // q is the root and father of y now
	    if(q!=p)
	    {
		// we force the root of y is the new root
		// we only update the relation of root of x to the root of y
		set[p] = q;
		rel[p] = (3-rel[x]+d-1+rel[y])%3; 
	    }
	    else
	    {
		if(d==1&&rel[x]!=rel[y])
		    ans++;
		else if(d==2 && (rel[x]+3-rel[y])%3!=1)
		    ans++;
	    }
	}
    }

    printf("%d\n",ans);
    return 0;
}
