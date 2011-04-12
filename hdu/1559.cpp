//http://acm.hdu.edu.cn/showproblem.php?pid=1559
/*
分类在dp里面，实际操作上有点像数字图像处理的integral image
*/
#include <stdio.h>
#include <string.h>

#define RANGE 1100
int matrix[RANGE][RANGE];

int main()
{
	freopen("input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(matrix,0,sizeof(matrix));
		int m,n,x,y;
		scanf("%d %d %d %d",&m,&n,&x,&y);
		for(int i = 1;i <= m;++i)
		{
			for(int j = 1;j <= n;++j)
			{
				int temp;
				scanf("%d",&temp);
				matrix[i][j] = matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1] + temp;
			}
		}
		int max = 0;
		for(int i = x;i <= m; ++i)
		{
			for(int j = y;j <= n; ++j)
			{
				int ans = matrix[i][j] + matrix[i-x][j-y] - matrix[i-x][j] -matrix[i][j-y];
				if(ans > max)
					max = ans;
			}
		}
		printf("%d\n",max);
	}
	return 0;
}