#include<cstdio>
#include<algorithm>
using namespace std;

int row;
int matrix[101][101];
int step[101][101];


void search()
{
    // first we copy the lowest layer
    for(int i = 0;i<row;++i)
    {
	step[row-1][i] = matrix[row-1][i];
    }

    // start add number from the second layer
    for(int i=row-2;i>=0;--i)
    {
	for(int j = 0;j<i+1;j++)
	{
	    step[i][j] = max(step[i+1][j],step[i+1][j+1])+matrix[i][j];
	}
    }
}


int main()
{
    scanf("%d",&row);
    for(int i = 0;i<row;++i)
    {
	for(int j = 0;j<i+1;++j)
	{
	    scanf("%d",&matrix[i][j]);
	}
    }

    search();

    printf("%d\n",step[0][0]);

    return 0;
}
