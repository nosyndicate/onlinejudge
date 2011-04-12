#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 2001;
const int K = 1001;
int w[N];
int f[N][K];
int main()
{
	int n,k;
	while(scanf("%d %d",&n,&k)!=EOF)
	{
		memset(f,-1,sizeof(f));
		for(int i = 1;i<=n;++i)
		{
			scanf("%d",&w[i]);
			f[i][0] = 0;
		}
		sort(w+1,w+n+1);
		int count;
		f[0][0] = 0;
		for(int i = 2;i<=n;++i)
		{
			count = i/2;
			for(int j = 1;j<=count;++j)
			{
				if(f[i-1][j]==-1)
					f[i][j]=f[i-2][j-1]+(w[i]-w[i-1])*(w[i]-w[i-1]);
				else
					f[i][j] = min(f[i-1][j],f[i-2][j-1]+(w[i]-w[i-1])*(w[i]-w[i-1]));
			}
		}
		printf("%d\n",f[n][k]);
	}
	return 0;
}