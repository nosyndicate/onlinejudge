//http://acm.hdu.edu.cn/showproblem.php?pid=1076
//原来想复杂了
#include<stdio.h>
int main()
{
	int t,n,i;
	long y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld %d",&y,&n);
		while(n!=0)
		{
			if((y%4==0&&y%100!=0)||y%400==0)
				n--;
			y++;
		}
		if(n==0)
			printf("%ld\n",y-1);
	}
}