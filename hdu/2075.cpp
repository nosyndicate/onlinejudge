//http://acm.hdu.edu.cn/showproblem.php?pid=2075
/*看题目被吓住了，思考了半天有何玄机，实际啥玄机都没有*/

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