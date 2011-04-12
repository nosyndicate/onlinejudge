//http://acm.hdu.edu.cn/showproblem.php?pid=1062
#include <stdio.h>
#include <stack>
using namespace std;
char a[1002];
stack<char> st;
int main()
{
	int n;
	bool flag = false;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		while(true)
		{
			char c = getchar();
			if(c!=32&&c!='\n')
				st.push(c);
			else
			{
				for(int j = st.size();j>0;--j)
				{
					printf("%c",st.top());
					st.pop();
				}
				if(c=='\n')
					break;
				else
					putchar(' ');
			}
		}
		printf("\n");
	}
	return 0;
}