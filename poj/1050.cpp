#include<stdio.h>

#define MAX 105

int num[MAX][MAX];




int main()
{
    int n;
    scanf("%d" &n);
    for(int i = 0;i<n;++i)
    {
	for(int j = 0;j<n;++j)
	{
	    scanf("%d",&num[i][j]);
	}
    }
    
    return 0;
}
