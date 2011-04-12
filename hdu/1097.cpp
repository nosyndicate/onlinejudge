//http://acm.hdu.edu.cn/showproblem.php?pid=1097
#include<stdio.h>
int metrix[10][4] = {{0,0,0,0},{1,1,1,1},{6,2,4,8},{1,3,9,7},{6,4,6,4},{5,5,5,5},{6,6,6,6},{1,7,9,3},{6,8,4,2},{1,9,1,9}};
int main()
{
	int a,b;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
			a%=10;
			b%=4;
			printf("%d\n",metrix[a][b]);
	}
	return 0;
}

/*#include"iostream"
using namespace std;
int main()
{
	int a,b,mul;
	int i;
	while(cin>>a>>b)
	{
		mul=1;
		a%=1000;
		b%=1000;
		for(i=1;i<=b;i++)
		{
			mul*=a;
			mul%=10;
		}
		cout<<mul<<endl;
	}
	return 0;
}*/
