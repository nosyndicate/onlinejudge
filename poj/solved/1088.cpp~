#include<cstdio>
using namespace std;

int matrix[101][101];
int length[101][101];
int row,column;
// dynamic algorithm
// using memorized deep search

// DP_search(i,j) = max(DP_search(i,j-1),DP_search(i-1,j),DP_search(i,j-1),DP_search(i,j+1)) + 1

/* in this problem, it a search problem, but if don't want to search same 
   branches again and again, so we record the search result of the branches and when we need it again, we just return the result before.*/


int DP_search(int i, int j)
{    
    if(length[i][j]>0)
	return length[i][j];

    int max_length = 0;
    if(i>0)
    {
	if(matrix[i][j]>matrix[i-1][j])
	{
	    int l = DP_search(i-1,j);
	    if(max_length<l)
		max_length = l;
	}
    }

    if(i<row-1)
    {
	if(matrix[i][j]>matrix[i+1][j])
	{
	    int l = DP_search(i+1,j);
	    if(max_length<l)
		max_length = l;
	}
    }

    if(j>0)
    {
	if(matrix[i][j]>matrix[i][j-1])
	{
	    int l = DP_search(i,j-1);
	    if(max_length<l)
		max_length = l;
	}
    }

    if(j<column-1)
    {
	if(matrix[i][j]>matrix[i][j+1])
	{
	    int l = DP_search(i,j+1);
	    if(max_length<l)
		max_length = l;
	}
    }
    
    length[i][j] = max_length+1;
    return max_length+1;
}


int main()
{
    scanf("%d %d",&row,&column);
    for(int i = 0;i<row;++i)
    {
	for(int j = 0;j<column;++j)
	{
	    scanf("%d",&matrix[i][j]);
	    length[i][j] = 0;
	}
    }


    //search the matrix length of each 
    for(int i = 0;i<row;++i)
    {
	for(int j = 0;j<column;++j)
	{
	    DP_search(i,j);
	}
    }

    int max = 0;
    for(int i = 0;i<row;++i)
    {
	for(int j = 0;j<column;++j)
	{
	    if(max<length[i][j])
		max = length[i][j];
	}
    }
    
    printf("%d\n",max);

    return 0;
}
