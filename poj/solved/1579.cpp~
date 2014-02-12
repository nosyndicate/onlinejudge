#include<cstdio>
using namespace std;

const int D = 21;
int matrix[D][D][D];

int a,b,c;


int search(int a,int b,int c)
{
    int result = -100;
    
    // we first start with two case that out of our bounds
    if(a<=0||b<=0||c<=0)
    {
	return 1;
    }
    
    if(a>20||b>20||c>20)
    {
	return search(20,20,20);
    }

    // if it is in the memory, we simply return it
    if(matrix[a][b][c]>0)
	return matrix[a][b][c];

    if(a<b&&b<c)
    {
	matrix[a][b][c] = search(a,b,c-1)+search(a,b-1,c-1)-search(a,b-1,c);
	return matrix[a][b][c];
    }
    
    // last case
    matrix[a][b][c] = search(a-1,b,c) + search(a-1,b-1,c) + search(a-1,b,c-1) - search(a-1,b-1,c-1);

    return matrix[a][b][c];


}



int main()
{
    for(int i = 0;i<D;++i)
    {
	for(int j = 0;j<D;++j)
	{
	    for(int k = 0;k<D;++k)
	    {
		matrix[i][j][k]=-100;
	    }
	}
    }


    // initialize the base case
    for(int i = 0;i<D;++i)
    {
	for(int j = 0;j<D;++j)
	{
	    matrix[i][j][0] = 1;
	    matrix[i][0][j] = 1;
	    matrix[0][i][j] = 1;
	}
    }


    while(1)
    {
	scanf("%d %d %d",&a,&b,&c);
	if(a==-1&&b==-1&&c==-1)
	    break;
	
	int result = search(a,b,c);

	// print the output
	printf("w(%d, %d, %d) = %d\n",a,b,c,result);
	
    }


    return 0;
}
