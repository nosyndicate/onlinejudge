//http://acm.hdu.edu.cn/showproblem.php?pid=1020
#include <iostream>
using namespace std;

int main()
{
	int t, i, num;
	char a[10002];

	scanf("%d%*c", &t);
	while(t --)
	{
		gets(a);

		num = 1;
		for(i = 0; a[i] != '\0'; i ++)
		{
			if(a[i] == a[i + 1])
				num ++;
			if(a[i] != a[i + 1] || a[i + 1] == '\0')
			{
				if(num == 1)
					printf("%c", a[i]);
				else
					printf("%d%c", num, a[i]);
				num = 1;
			}
		}

		printf("\n");
	}

	return 0;
}
