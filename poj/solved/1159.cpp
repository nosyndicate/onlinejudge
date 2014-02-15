/*
  dynamic programming
  longest common string
 */

#include<cstdio>
#include<cstring>
using namespace std;


char strA[5002],strB[5002];
short mat[5002][5002]; // use short instead of int


void reverse(char strB[], char strA[], int n)
{
    for(int i = 1;i<=n;++i)
    {
	strB[i] = strA[n+1-i];
    }
    strB[n+1]='\0';
}



int max(int a,int b)
{
    if(a>b)
	return a;
    else 
	return b;
}


int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",strA+1);// we start with 1
    
    reverse(strB,strA,n);
    memset(mat,0,sizeof(mat));

    for(int i = 1;i<=n;++i)
    {
	for(int j = 1;j<=n;++j)
	{
	    if(strA[i]==strB[j])
		mat[i][j] = mat[i-1][j-1]+1;
	    else
		mat[i][j] = max(mat[i][j-1],mat[i-1][j]);
	}
    }

    printf("%d\n",n-mat[n][n]);

    return 0;
}
