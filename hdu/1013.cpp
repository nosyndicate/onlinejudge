//http://acm.hdu.edu.cn/showproblem.php?pid=1013
#include <stdio.h>

int GetNum(char* p)
{
	int temp = 0;
	while(*p!='\0')
	{
		temp+=(*p-'0');
		p++;
	}
	int a = temp%9;
	if(a==0)
		a = 9;
	return a;
}

int main()
{
	char num[1000];
	scanf("%s",num);
	while(num[0]!='0')
	{
		int ret = GetNum(num);
		printf("%d\n",ret);
		scanf("%s",num);
	}
	return 0;
}