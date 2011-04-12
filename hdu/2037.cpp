//http://acm.hdu.edu.cn/showproblem.php?pid=2037
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct A
{
	int s;
	int e;
};

int cmp(A a,A b)
{
	return a.e<b.e;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		vector<A> arr;
		int time = 1,flag = 0;
		for(int i = 0;i<n;++i)
		{
			A t;
			scanf("%d %d",&t.s,&t.e);
			arr.push_back(t);
		}
		sort(arr.begin(),arr.end(),cmp);	
		for(int i = 1;i<arr.size();++i)
		{
			if(arr[i].s>=arr[flag].e)
			{
				time++;
				flag = i;
			}
		}
		printf("%d\n",time);
	}
	return 0;
}