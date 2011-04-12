//http://acm.hdu.edu.cn/showproblem.php?pid=1060
#include<stdio.h>
#include<math.h>

int main()
{
	int t, n, r;
	double d;
	for(scanf("%d", &t); t; --t)
	{
		scanf("%d", &n);
		d = n * log10(n * 1.0);
		d -= (__int64)d;
		r = pow(10.0, d);
		printf("%d\n", r);
	}
	return 0;
}
