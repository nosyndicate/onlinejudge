/*
  disjoint set
  relationship
 */
#include<cstdio>

using namespace std;

int p[2005];
int rel[2005]; //0 for same genders as the father node, 1 for opposite gender

void initialize(int n)
{
    for(int i = 1;i<=n;++i)
    {
	p[i] = i;
	rel[i] = 0;// every bugs has the same gender as itself
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
	rel[x] = (rel[x]+rel[temp])%2;
	return p[x];
    }
}


int main()
{
    int s;
    scanf("%d",&s);
    for(int i = 1;i<=s;++i)
    {
	int b,inter;
	bool suspicious = false;
	scanf("%d %d",&b,&inter);
	initialize(b);
	for(int j = 0;j<inter;++j)
	{
	    int x,y;
	    scanf("%d %d",&x,&y);
	    if(!suspicious)
	    {
		int fx = find(x);
		int fy = find(y);
		//if in the same set already, check the gender compatibility
		if(fx==fy)
		{
		    if(rel[x]==rel[y])
			suspicious = true;
		}
		else //if not in the same set, merge it
		{
		    p[fx] = fy;
		    rel[fx] = (rel[x]+1+rel[y])%2; // update the relationship
		}
	    }
	    
	}
	printf("Scenario #%d:\n",i);
	if(suspicious)
	    printf("Suspicious bugs found!\n\n");
	else
	    printf("No suspicious bugs found!\n\n");
		
    }
}
