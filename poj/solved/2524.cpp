/*
  disjoint set
 */

#include<cstdio>


int p[50005];

void initialize_set(int n)
{
    for(int i = 1;i<=n;++i)
    {
	p[i] = i;
    }
}

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




int main()
{
    int m,n,k=1;
    while(true)
    {
	scanf("%d %d",&n,&m);
	if(n==0&m==0)
	    break;
	initialize_set(n);
	
	int ans = n;
	for(int i = 0;i<m;++i)
	{
	    int a,b;
	    scanf("%d %d",&a,&b);
	    
	    a = find(a);
	    b = find(b);
	    
	    if(a!=b)
	    {
		p[a] = b;
		ans--;
	    }
	}

	printf("Case %d: %d\n",k++,ans);

    }
    return 0;
}
