//http://acm.hdu.edu.cn/showproblem.php?pid=1085
#include <stdio.h>
int main()
{
	int one,two,five;
	while(scanf("%d %d %d",&one,&two,&five)&&(one+two+five!=0))
	{
		if(one<1)
			printf("1\n");
		else if(one+2*two<4)
			printf("%d\n",one+2*two+1);
		else 
			printf("%d\n",one+2*two+5*five+1);
	}
	return 0;
}