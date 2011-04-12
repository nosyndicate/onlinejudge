//http://acm.hdu.edu.cn/showproblem.php?pid=1061
#include<stdio.h>
int metrix[10][4] = {{0,0,0,0},{1,1,1,1},{6,2,4,8},{1,3,9,7},{6,4,6,4},{5,5,5,5},{6,6,6,6},{1,7,9,3},{6,8,4,2},{1,9,1,9}};
int main()
{
	int t,a;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&a);
		int i = a%10;
		int j = a%4;
		printf("%d\n",metrix[i][j]);
	}
	return 0;
}