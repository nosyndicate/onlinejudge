//http://acm.hdu.edu.cn/showproblem.php?pid=1008
#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
	int n,prev = 0,next,sum = 0;
	int j = 0;
	vector<int> sums;
	scanf("%d",&n);
	while(n!=0)
	{
		for(int i = 0;i<n;++i)
		{
			scanf("%d",&next);
			sum+=((next-prev)>0)?(next-prev)*6:(prev-next)*4;
			sum+=5;
			prev = next;
		}
		sums.push_back(sum);
		j++;
		prev = 0;
		sum = 0;
		scanf("%d",&n);
	}
	for(int i = 0;i<j;++i)
	{
		printf("%d\n",sums[i]);
	}
	return 0;
}