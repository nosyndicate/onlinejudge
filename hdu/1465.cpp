//http://acm.hdu.edu.cn/showproblem.php?pid=1465
#include <stdio.h>
int main()
{
	__int64 n,a[21];
	a[1] = 0;
	a[2] = 1;
	for(int i = 3;i<21;++i)
		a[i] = (i-1)*(a[i-1]+a[i-2]);
	while(scanf("%d",&n)!=EOF)
	{
		printf("%I64d\n",a[n]);
	}
}

/*
��N���ŵ�ʱ��,ǰ��N-1���ſ�����N-1����N-2���װ
ǰ�ߣ�����ÿ�ִ�װ,�ɴ�N-1����������ȡһ��͵�N���װ,��=F(N-1)*(N-1)
���߼�,ֻ����ûװ����Ƿ�͵�N�⽻���ŷ�,ûװ����Ƿ������ǰ��N-1���е�����һ��,��=F(N-2)*(N-1)
*/