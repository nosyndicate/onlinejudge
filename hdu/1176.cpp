//http://acm.hdu.edu.cn/showproblem.php?pid=1176
#include <stdio.h>
#include <algorithm>
using namespace std;
const int T = 100001;
const int x = 11;
int f[T][x];
int main()
{
	int n,a,b,maxt = 0;
	while((scanf("%d",&n)!=EOF)&&(n!=0))
	{
		memset(f, 0, sizeof(f));
		for(int i = 1;i<=n;++i)
		{
			scanf("%d %d",&a,&b);
			f[b][a]++;
			if(b>maxt)
				maxt = b;
		}
		for(int i = maxt - 1;i>=0;--i)
		{
			for(int j = 0;j<=10;++j)
			{
				if(j == 0)
				{
					f[i][j] += max(f[i+1][j],f[i+1][j+1]);
				}
				else if(j==10)
				{
					f[i][j]+= max(f[i+1][j-1],f[i+1][j]);
				}
				else
				{
					int m = max(f[i+1][j-1],f[i+1][j]);
					f[i][j] += max(m,f[i+1][j+1]);
				}
			}
		}
		printf("%d\n",f[0][5]);
	}
}