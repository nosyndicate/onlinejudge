//http://acm.hdu.edu.cn/showproblem.php?pid=1711
/*第一次做KMP，找个模板题练练手*/

#include<stdio.h>
#include <vector>
using namespace std;
#define OUTOFRANGE 1000001
vector<int> A,B;
vector<int> next;
int m,n;

int match()
{
	int num = -1,j = 0;
	for(int i = 1;i <= n;++i)
	{
		while((j > 0)&&(B[j+1] != A[i]))
			j = next[j];
		if(B[j+1] == A[i])
			j++;
		if(j == m)
		{
			num = i - j + 1;
			break;
		}
	}
	return num;
}

void getNextArr()
{
	next.clear();
	next.assign(m+10,0);
	next[1] = 0;
	int j = 0;
	for(int i = 2;i <= m;++i)
	{
		while((j > 0)&&(B[j+1] != B[i]))
			j = next[j];
		if(B[j+1] == B[i])
			j++;
		next[i] = j;
	} 
}


int main()
{
	freopen("input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{ 
		scanf("%d %d",&n,&m);
		A.clear();B.clear();
		A.push_back(OUTOFRANGE);
		B.push_back(OUTOFRANGE);
		for(int i = 1;i <= n;++i)
		{
			int temp;
			scanf("%d",&temp);
			A.push_back(temp);
		}
		for(int i = 1;i <= m;++i)
		{
			int temp;
			scanf("%d",&temp);
			B.push_back(temp);
		}
		
		getNextArr();

		int num = match();

		printf("%d\n",num);
	}
	return 0;
}