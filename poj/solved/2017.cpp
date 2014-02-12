/*
	simulation
*/
#include<cstdio>

using namespace std;
int s[12]={0};
int t[12]={0};

int main()
{
    int n;
    while(true)
    {
	scanf("%d",&n);
	if(n==-1)
	    break;
	
	for(int i=1;i<=n;++i)
	{
	    scanf("%d %d",&s[i],&t[i]);
	}
	int total = 0;
	for(int i = 1;i<=n;++i)
	{
	    total+=(s[i]*(t[i]-t[i-1]));
	}
	printf("%d miles\n",total);
    }
    return 0;
}
