//http://acm.hdu.edu.cn/showproblem.php?pid=2017

/*C������ϰ�⣬��ˮ��ˢ��λ������*/

#include <cstdio>


int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		char c;
		int sum = 0;
		while(c = getchar())
		{
			if(c == '\n'||c == EOF)
				break;
			if('0'<=c&&c<='9')
				sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}