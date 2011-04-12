//http://acm.hdu.edu.cn/showproblem.php?pid=1257
/*
Dilworth定理：最小链划分 = 最长反链的长度
*/
#include <stdio.h>
#include <vector>
using namespace std;
int N;
vector<int> arr;
vector<int> dp;

int LIS()
{
	dp.assign(N,0);
	dp[0] = 1;
	for(int i = 1;i < dp.size();++i)
	{
		int max = 0;
		for(int j = 0;j < i;++j)
		{
			if((arr[i] > arr[j])&&(dp[j] > max))
				max = dp[j];
		}
		dp[i] = max + 1;
	}

	int ret = 0;
	for(int i = 0;i < dp.size();++i)
		if(ret < dp[i])
			ret = dp[i];
	return ret;
}


int main()
{
	//freopen("input.txt","r",stdin);
	while(scanf("%d",&N) != EOF)
	{
		arr.assign(N,0);
		for(int i = 0;i < N;++i)
		{
			int buffer;
			scanf("%d",&buffer);
			arr[i] = buffer;
		}

		int ans = LIS();
		printf("%d\n",ans);
	}
	return 0;
}