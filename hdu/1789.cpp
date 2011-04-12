//http://acm.hdu.edu.cn/showproblem.php?pid=1789
//先做扣分多的，把它安排在截止日期前最后一天
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Record
{
	int d,s;
};

bool sortWithS(Record& leftValue,Record& rightValue)
{
	if(leftValue.s != rightValue.s) return leftValue.s > rightValue.s;
	else return leftValue.d < rightValue.d;
}

int main()
{
	//freopen("input.txt","r",stdin);
	int t,n = 0;
	scanf("%d",&t);
	while(t--)
	{
		vector<Record> records;
		bool visited[1000];
		scanf("%d",&n);
		for(int i = 0;i < n;++i)
		{
			Record record;
			scanf("%d",&record.d);
			records.push_back(record);
		}
		for(int i = 0;i < n;++i)
			scanf("%d",&records[i].s); 
		sort(records.begin(),records.end(),sortWithS);
		memset(visited,0,sizeof(visited));
		int totalScore = 0;
		for(int i = 0;i < n;++i)
		{
			int j;
			for(j = records[i].d;j > 0;--j)
			{
				if(false == visited[j])
				{
					visited[j] = true;
					break;
				}
			}
			if(0 == j)
				totalScore += records[i].s;
		}
		printf("%d\n",totalScore);
	}
	return 0;
}