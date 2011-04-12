//http://acm.hdu.edu.cn/showproblem.php?pid=2019
/*3遍才过啊，夏神说鄙视我啊~~~~*/
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	int m,n;
	while(scanf("%d %d",&n,&m),n+m)
	{
		vector<int> arr;
		bool flag = false;
		for(int i = 0;i < n;++i)
		{
			int temp;
			scanf("%d",&temp);
			if(m < temp&&!flag)
			{
				arr.push_back(m);
				flag = !flag;
			}			
			arr.push_back(temp);
		}
		if(arr.size() == n)
			arr.push_back(m);
		for(int i = 0; i < arr.size() - 1;++i)
			printf("%d ",arr[i]);
		printf("%d\n",arr[arr.size()-1]);
	}
	return 0;
}