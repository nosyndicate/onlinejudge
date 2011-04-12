//http://acm.hdu.edu.cn/showproblem.php?pid=1090
#include <stdio.h>
int main()
{ 
	int n,i,a,b;
    scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&a, &b);
        printf("%d\n",a+b);
	}
} 
