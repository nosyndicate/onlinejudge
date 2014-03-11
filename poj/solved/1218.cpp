/*
  simulation
  but could also treat as a math problem
*/
#include<cstdio>
#include<cstring>
using namespace std;

bool cell[101];

int main()
{
    int c;
    scanf("%d",&c);
    while(c--)
    {
	int n;
	scanf("%d",&n);
	memset(cell,0,sizeof(cell));
	for(int i = 1;i<=n;++i)
	{
	    for(int j = i;j<=n;j+=i)
	    {
		cell[j] = !cell[j];	        
	    }
	}
	int ans = 0;
	for(int i = 1;i<=n;++i)
	{
	    if(cell[i])
		ans++;
	}
	printf("%d\n",ans);
    }
    return 0;
}
