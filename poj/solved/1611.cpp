/*
  disjoint set
 */
#include<cstdio>
using namespace std;

int s[30005];
int count[30005];

void initialize_set(int n)
{
    for(int i = 0;i<n;++i)
    {
	s[i] = i;
	count[i] = 1;
    }
}

int find(int x)
{
    if(s[x]==x)
	return x;
    else
    {
	s[x] = find(s[x]);
	return s[x];
    }
}

void merge(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if(count[x]>count[y])
    {
	count[x] += count[y]; // x hold the number of elements
	s[y] = x; // x is the new root
    }
    else
    {
	count[y] += count[x];
	s[x] = y;
    }
}

int main()
{
    int n,m;
    while(true)
    {
	scanf("%d %d",&n,&m);
	if(m==0&n==0)
	    break;

	initialize_set(n);

	for(int i = 0;i<m;++i)
	{
	    int k,a = -1;
	    scanf("%d",&k);
	    for(int j = 0;j<k;++j)
	    {
		int b;
		scanf("%d",&b);
		if(a==-1)
		{
		    a = b;
		    continue;
		}
		else
		{
		    int p = find(a),q = find(b);
		    if(p!=q)
			merge(a,b);
		}
	    }

	}
	printf("%d\n",count[find(0)]);
    }
    return 0;
}
