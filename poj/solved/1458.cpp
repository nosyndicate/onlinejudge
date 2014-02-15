/*
  dynamic programming
  longest common string
 */

#include<cstdio>
#include<cstring>
using namespace std;


char strA[5002],strB[5002];
int mat[2][5002];



int max(int a,int b)
{
    if(a>b)
	return a;
    else 
	return b;
}


int main()
{
    while(scanf("%s %s",strA+1,strB+1)!=EOF)
    {
	memset(mat,0,sizeof(mat));
	int l1 = strlen(strA+1);
	int l2 = strlen(strB+1);
	for(int i = 1;i<=l1;++i)
	{
	    for(int j = 1;j<=l2;++j)
	    {
		// using rolling array to save place
		if(strA[i]==strB[j])
		    mat[i%2][j] = mat[(i+1)%2][j-1]+1;
		else
		    mat[i%2][j] = max(mat[i%2][j-1],mat[(i+1)%2][j]);
	    }
	}
	
	printf("%d\n",mat[l1%2][l2]);
    }
    return 0;
}
