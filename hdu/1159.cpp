//http://acm.hdu.edu.cn/showproblem.php?pid=1159
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int l[1000][1000] = {0};
int main()
{
	string a,b;
	while(cin>>a>>b)
	{
		for(int i = 0;i<=a.size();++i)
			for(int j = 0;j<=b.size();++j)
				l[i][j] = 0;
		for(int i = 1;i<=a.size();++i)
		{
			for(int j = 1;j<=b.size();++j)
			{
				if(a[i-1]==b[j-1])
					l[i][j] = l[i-1][j-1]+1;
				else if(l[i-1][j]<=l[i][j-1])
					l[i][j] = l[i][j-1];
				else if(l[i-1][j]>l[i][j-1])
					l[i][j] = l[i-1][j];
			}
		}
		printf("%d\n",l[a.size()][b.size()]);
	}
	return 0;
}