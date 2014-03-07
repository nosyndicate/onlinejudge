/*
  simulation
*/
#include<cstdio>
#include<cstring>
using namespace std;

int num[9] = {1,2,3,4,5,6,7,8,9};


int mat[21][21];


int main()
{
    int n,s;
    scanf("%d %d",&n,&s);
    memset(mat,-1,sizeof(mat));
    int index = s-1;
    for(int j = 0;j<n;++j)
    {
	for(int i = 0;i<n;++i)
	{
	    if(i<=j)
	    {
		mat[i][j] = num[index%9];
		index++;
	    }
	}
    }

    for(int i = 0;i<n;++i)
    {
	bool first = true;
	for(int j = 0;j<n;++j)
	{
	    char c;
	    if(mat[i][j]==-1)
		c = ' ';
	    else
		c = '0'+mat[i][j];

	    if(first)
	    {
		printf("%c",c);
		first = false;
	    }
	    else
		printf(" %c",c);
	}
	printf("\n");
    }

}
