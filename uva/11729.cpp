#include<cstdio>
#include<algorithm>
using namespace std;

const int maxm = 10000+5;

struct time
{
    int b;
    int j;
};

time t[maxm];


bool comp(time a, time b)
{
    return a.j>b.j;
}

int main()
{
    int c = 1;
    int n;
    while(scanf("%d",&n)==1)
    {
	if(n==0)
	    break;

	for(int i = 0;i<n;++i)
	{
	    scanf("%d %d",&t[i].b,&t[i].j);
	}

	sort(t,t+n,comp);
	
	int maxtime = 0,start = 0;
	for(int i = 0;i<n;++i)
	{
	    if(i==0)
	    {
		maxtime = start + t[i].b + t[i].j;
		start = t[i].b;
	    }
	    else
	    {
		if(start+t[i].b+t[i].j>maxtime)
		    maxtime = start + t[i].b + t[i].j;
		start = start + t[i].b;
	    }

	}
	printf("Case %d: %d\n",c++,maxtime);
	
    }
    return 0;
}
