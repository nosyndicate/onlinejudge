//http://acm.hdu.edu.cn/showproblem.php?pid=2075
/*����Ŀ����ס�ˣ�˼���˰����к�������ʵ��ɶ������û��*/

#include<cstdio>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		__int64 a,b;
		scanf("%I64d %I64d",&a,&b);
		printf("%s\n",a%b?"NO":"YES");
	}
	return 0;
}