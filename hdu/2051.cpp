//http://acm.hdu.edu.cn/showproblem.php?pid=2051
#include <stdio.h>
#include <stack>
using namespace std;

void Display(stack<int> s)
{
	int l = s.size();
	for(int i = 0;i<l;++i)
	{
		printf("%d",s.top());
		s.pop();
	}
	printf("\n");
}


int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int t = n;
		stack<int> s;
		while(t!=0)
		{
			int m = t%2;
			s.push(m);
			t = (t-m)/2;
		}
		Display(s);
	}
	return 0;
}