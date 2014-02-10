#include<stdio.h>
#include<string.h>
using namespace std;
#define RANGE 101
int b[RANGE][RANGE];
int p[RANGE][RANGE];

int t,n;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
	memset(b,0,sizeof(b));
	memset(p,0,sizeof(p));
	scanf("%d",&n);
	for(int i = 0;i<n;++i)
	{
	    int m;
	    scanf("%d",&m);
	    for(int j = 0;j<m;++j)
	    {
		scanf("%d %d",&b[])
	    }
	}
    }
    return 0;
}
