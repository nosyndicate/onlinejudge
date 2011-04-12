//http://acm.hdu.edu.cn/showproblem.php?pid=1267
/*考虑字符串为H结尾和以D结尾的情况，dp[i][j] = dp[i][j-1] + dp[i-1][j]*/
#include <stdio.h>
#include <string.h>
#define RANGE 25
__int64 dp[RANGE][RANGE];
int main()
{
	//freopen("input.txt","r",stdin);
	memset(dp,0,sizeof(dp));
	for(int i = 0; i <= 20;++i)
	{
		dp[i][0] = 1;
		dp[0][i] = 0;
	}
	for(int i = 1;i <= 20;++i)
	{
		for(int j = 1; j <= 20;++j)
		{
			if(i < j)
				dp[i][j] = 0;
			else
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}
	int m,n;
	while(scanf("%d %d",&m,&n) != EOF)
	{
		printf("%I64d\n",dp[m][n]);
	}
}