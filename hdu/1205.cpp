//http://acm.hdu.edu.cn/showproblem.php?pid=1205
/*
water,ֻҪ���ǹ��ֳ����ݣ���������������Ϊһ�ݣ������ĺ�����Ϊһ��
һ��Ҫע�����ݷ�Χ��������������
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
