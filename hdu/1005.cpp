//http://acm.hdu.edu.cn/showproblem.php?pid=1005
#include <stdio.h>
#include <vector>
using namespace std;
vector<int> queue;

bool flag[7][7];

void init()
{
	for(int i = 0;i<7;++i)
		for(int j = 0;j<7;++j)
			flag[i][j] = false;
}

int main()
{
	int a,b,n;
	scanf("%d %d %d",&a,&b,&n);
	while(a!=0&&b!=0&&n!=0)
	{
		int fn,count = 1;
		init();queue.clear();
		queue.push_back(1);queue.push_back(1);
		while(1)
		{
			fn = (a*queue[count]+b*queue[count-1])%7;
			queue.push_back(fn);count++;
			if(flag[queue[count]][queue[count-1]] == true)
				break;
			else
			{
				flag[queue[count]][queue[count-1]] = true;
			}
		}
		count = count - 1;
		if(n < count)
			printf("%d\n",queue[n-1]);
		else
		{
			int j;
			for(j = 0;;++j)
				if(queue[count] == queue[j] && queue[count + 1] == queue[j+1])
					break;
			n = (n - j)%(count - j);
			if(n == 0)
				n = count - j;
			n += j;
			printf("%d\n",queue[n-1]);
		}
		scanf("%d %d %d",&a,&b,&n);
	}
	return 0;
}