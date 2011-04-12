//http://acm.hdu.edu.cn/showproblem.php?pid=2059
/*
以后注意double到int的转换
*/
#include <stdio.h>
#include <string.h>
int L;//跑道的总长度
int N,C,T;//充电站的个数，电动车冲满电以后能行驶的距离以及每次充电所需要的时间
int VR,VT1,VT2;//兔子跑步的速度，乌龟开电动车的速度，乌龟脚蹬电动车的速度
int dist[110];
double dp[110];
int main()
{
	//freopen("input.txt","r",stdin);
	while(scanf("%d",&L) != EOF)
	{
		memset(dp,0,sizeof(dp));
		memset(dist,0,sizeof(dist));
		scanf("%d %d %d",&N,&C,&T);
		scanf("%d %d %d",&VR,&VT1,&VT2);
		dist[0] = 0;
		for(int i = 1;i <= N;++i)
		{
			scanf("%d",&dist[i]);
		}
		
		double rabbitTime = (double)L / VR;
		double turtleTime = 0;

		dp[0] = 0;
		dist[N+1] = L;
		for(int i = 1;i <= N + 1;++i)
		{
			double minTime = 0xFFFF;
			for(int j = 0; j < i;++j)
			{
				int dis = dist[i] - dist[j];
				double runtime = dis > C ? (double)C / VT1 + (double)(dis - C) / VT2 :((double)dis / VT1);
				if(j)
					runtime += T;
				runtime += dp[j];
				if(runtime < minTime)
					minTime = runtime;
			}
			dp[i] = minTime;
		}

		turtleTime = dp[N+1];
		if(rabbitTime < turtleTime)
			printf("Good job,rabbit!\n");
		else
			printf("What a pity rabbit!\n");
	}
	return 0;
}