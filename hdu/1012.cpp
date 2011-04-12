//http://acm.hdu.edu.cn/showproblem.php?pid=1012
#include <stdio.h>
double e = 0;
double GetValue(int i)
{
	double ret = 1;
	if(0!=i)
	{
		for(int j = 1;j<=i;++j)
		{
			ret*=j;
		}
	}
	return 1/ret;
}

int main()
{
	printf("n e\n");
	printf("- -----------\n");
	for(int i = 0;i<=9;++i)
	{
		printf("%d ",i);
		e += GetValue(i);
		if(i==8) printf("%.9f\n",e);
		else printf("%.10g\n",e);
	}
}