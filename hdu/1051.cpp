//http://acm.hdu.edu.cn/showproblem.php?pid=1051
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

struct Wood
{
	int l;
	int w;
	bool flag;
};

int cmp(Wood a,Wood b)
{
	if(a.l<=b.l&&a.w<=b.w)
		return true;
	return false;
}
int cmpl(Wood a,Wood b)
{
	return a.l<b.l;
}
int cmpw(Wood a,Wood b)
{
	return a.w<b.w;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,min = 0;
		vector<Wood> v;
		scanf("%d",&n);
		for(int i = 0;i<n;++i)
		{
			Wood a;
			scanf("%d %d",&a.l,&a.w);
			a.flag = false;
			v.push_back(a);
		}
		sort(v.begin(),v.end(),cmpw);
		sort(v.begin(),v.end(),cmpl);
		for(int i = 0;i<v.size();++i)
		{
			if(v[i].flag==false)
			{
				min++;
				v[i].flag = true;
				Wood temp = v[i];
				for(int j = i+1;j<v.size();++j)
				{
					if(v[j].flag==false&&cmp(temp,v[j]))
					{
						v[j].flag = true;
						temp = v[j];
					}
				}
			}
		}
		printf("%d\n",min);
	}
	return 0;
}