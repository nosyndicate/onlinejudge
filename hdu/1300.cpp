//http://acm.hdu.edu.cn/showproblem.php?pid=1300
/*
有点类似于龟兔赛跑那道题的转移方程
dp[i] = min(dp[j] + (sum[j] - sum[i] + 10) * price[i]) (j < i)
*/
#include <stdio.h>
#include <string.h>
#define CATEGORY 110

int t,c;
int price[CATEGORY],need[CATEGORY],sum[CATEGORY],dp[CATEGORY];


int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%d",&t);
	while(t--)
	{
		memset(price,0,sizeof(price));
		memset(need,0,sizeof(need));
		memset(sum,0,sizeof(sum));
		memset(dp,0,sizeof(dp));		   
		scanf("%d",&c);
		for(int i = 1;i <= c;++i)
		{
			scanf("%d %d",&need[i],&price[i]);
		}
		sum[0] = 0;
		for(int i = 1;i <= c;++i)
		{
			sum[i] = sum[i-1] + need[i];
		}
		dp[0] = 0;
		for(int i = 1;i <= c;++i)
		{
			int min = 99999999;
			for(int j = 0;j < i;++j)
			{
				int value = dp[j] + (sum[i] - sum[j] + 10) * price[i];
				if(value < min)
					min = value;
			}
			dp[i] = min;
		}
		printf("%d\n",dp[c]);
	}
	return 0;
}