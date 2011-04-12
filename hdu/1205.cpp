//http://acm.hdu.edu.cn/showproblem.php?pid=1205
/*
water,只要把糖果分成两份，输入里面最大的数为一份，其他的合起来为一份
一定要注意数据范围啊！！！！！！
*/
#include<stdio.h>

int main()
{
	__int64 T,N,i,j,num,max,sum;
	scanf("%I64d",&T);
	for(i=0;i<T;i++)
	{
		max=0;sum=0;
		scanf("%I64d",&N);
		for(j=0;j<N;j++)
		{
			scanf("%I64d",&num);
			sum+=num;
			if(num>max) max=num;
		}
		sum-=max;
		if(max>sum+1) printf("No\n");
		else printf("Yes\n");
	}
}
