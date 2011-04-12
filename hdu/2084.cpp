//http://acm.hdu.edu.cn/showproblem.php?pid=2084
#include <stdio.h>
#include <vector>
using namespace std;
#define N 100
int main()
{
	int t,l,temp;
	scanf("%d",&t);
	for(int i = 0;i<t;++i)
	{
		vector<int> tower[N];
		scanf("%d",&l);
		for(int j = 0;j<l;++j)
		{
			for(int k = 0;k<j+1;++k)
			{
				scanf("%d",&temp);
				tower[j].push_back(temp);
			}
		}
		for(int j = l-2;j>=0;--j)
		{
			for(int k = 0;k<=j;++k)
				tower[j][k]+=tower[j+1][k]>tower[j+1][k+1]? tower[j+1][k]:tower[j+1][k+1];
		}
		printf("%d\n",tower[0][0]);
	}
}