//http://acm.hdu.edu.cn/showproblem.php?pid=1081
//����ö�٣�����ʹ������Ӷκ�
#include <stdio.h>
#include <string.h>
int matrix[100][100];
int b[100];
int MaxArray(int n,int arr[])//һά���
{
	int b=0,sum=-10000000;
	for(int i=0;i<n;i++)
	{
		if(b>0) b+=arr[i];
		else b=arr[i];
		if(b>sum) sum=b;
	}
	return sum;  
}
int MaxMatrix(int n,int m[][100])//��ά���
{
	int sum = 0,max=-10000;
	for(int i = 0;i<n;++i)
	{
		for(int k = 0;k<n;++k)
			b[k] = 0;
		for(int j = i;j<n;++j)//����ö��
		{
			for(int k = 0;k<n;++k)
				b[k]+=m[j][k];
			sum = MaxArray(n,b);//����������Ӷκ�
			if(max<sum)
				max = sum;
		}
	}
	return max;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i = 0;i<n;++i)
			for(int j = 0;j<n;++j)
				scanf("%d",&matrix[i][j]);
		int ret = MaxMatrix(n,matrix);
		printf("%d\n",ret);
	}
	return 0;
}