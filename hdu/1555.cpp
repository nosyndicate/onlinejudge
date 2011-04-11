//http://acm.hdu.edu.cn/showproblem.php?pid=1555
/*water,ÎªÁËÉıÅÅÎ»*/
#include<stdio.h>

int main()
{
	//freopen("input.txt","r",stdin);
	int m,k;
	while(scanf("%d %d",&m,&k) != EOF)
	{
		if(0 == m && 0 == k)
			break;
		int d = m;
		while((m - m % k) >= k)
		{
			int changeday = m - m % k;
			d += (changeday / k);
			m =  m + changeday / k - changeday;
		}
		printf("%d\n",d);
	}
	return 0;
}