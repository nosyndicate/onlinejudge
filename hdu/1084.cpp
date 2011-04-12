//http://acm.hdu.edu.cn/showproblem.php?pid=1084
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int grade[9] = {50,60,65,70,75,80,85,90,95};
struct Record  
{
	int n,p,h,m,s,g;
	bool operator < (Record& rightValue)
	{
		if(this->p != rightValue.p) return this->p > rightValue.p;//先按照做出题目的顺序排序，大的在前
		if(this->h != rightValue.h) return this->h < rightValue.h;//再按照做出题目的时间排序，小的在前
		if(this->m != rightValue.m) return this->m < rightValue.m;
		if(this->s != rightValue.s) return this->s < rightValue.s;
	}
};

bool SortWithN(Record& leftValue,Record& rightValue)
{
	return leftValue.n < rightValue.n;
}


int n,p;
int main()
{
	while(true)
	{
		scanf("%d",&n);
		if(0 > n)
			break;
		vector<Record> records;
		for(int i = 0;i < n;++i)
		{
			Record t;
			scanf("%d %d:%d:%d",&t.p,&t.h,&t.m,&t.s);
			t.n = i;
			records.push_back(t);
		}
		sort(records.begin(),records.end());
		for(int i = 0;i < records.size();)
		{
			int segment = 0;
			if(5 == records[i].p)
				records[i].g = 100;
			else if(0 == records[i].p)
				records[i].g = 50;
			else
			{
				for(int j = i;(records.begin() + j != records.end())&&(records[i].p == records[j].p);++j,++segment);
				for(int k = i;(records.begin() + k != records.end())&&(records[i].p == records[k].p);++k)
				{
					if((k - i) < (segment / 2))
						records[k].g = grade[records[i].p * 2];
					else
						records[k].g = grade[records[i].p * 2 - 1];
				}

			}
			if(0 != segment)
				i += segment;
			else
				++i;
		}
		sort(records.begin(),records.end(),SortWithN);
		for(int i = 0;i < records.size();++i)
			printf("%d\n",records[i].g);
		printf("\n");
	}
	return 0;
}