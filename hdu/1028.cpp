//http://acm.hdu.edu.cn/showproblem.php?pid=1028
#include <stdio.h>
__int64 a[121][121];
//a[n][m]����������������n�����в�ͬ�Ļ����У���������������m�Ļ��ָ���
int main()
{
	for(int n = 1;n<121;++n)
		for(int m = 1;m<121;++m)
		{
			if(n==1&&m==1)
				a[n][m] = 1;
			else if(n<m)
				a[n][m] = a[n][n];
			else if(n==m)
				a[n][m] = a[n][m-1]+1;
			else
				a[n][m] = a[n][m-1] + a[n-m][m];
		}
	int t;
	while(scanf("%d",&t)!=EOF)
	{
		printf("%I64d\n",a[t][t]);
	}
}