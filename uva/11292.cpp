#include<cstdio>
#include<algorithm>
using namespace std;

const int maxnum = 20000+5;
int head[maxnum];
int knight[maxnum];

int main()
{
    int m,n;
    while(scanf("%d %d",&n,&m)==2)
    {
	int money = 0;
	if(n==0&m==0)
	    break;
	for(int i = 0;i<n;++i)
	    scanf("%d",&head[i]);
	for(int i = 0;i<m;++i)
	    scanf("%d",&knight[i]);
	sort(head,head+n);
	sort(knight,knight+m);
	int cutoff = 0;
	for(int i = 0;i<m;++i)
	{
	    if(knight[i]>=head[cutoff])
	    {
		money+=knight[i];
		cutoff++;
		if(cutoff==n)
		    break;
	    }
	}
	if(cutoff<n)
	    printf("Loowater is doomed!\n");
	else
	    printf("%d\n",money);
    }
    return 0;
}
