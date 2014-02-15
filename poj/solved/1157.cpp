/*
  dynamic programming
 */

#include<cstdio>
#include<cstring>

using namespace std;

int v_mat[110][110];
int dp[110][110];

int max(int a,int b)
{
    if(a>b)
	return a;
    else 
	return b;
}


int main()
{
    int f,v;
    memset(v_mat,0,sizeof(v_mat));
    // be carefule with the initialization
    for(int i = 0;i<110;++i)
    {
	for(int j = 0;j<110;++j)
	    dp[i][j] = -10000;
    }
    scanf("%d %d",&f,&v);
    for(int i = 1;i<=f;++i)
    {
	for(int j = 1;j<=v;++j)
	{
	    scanf("%d",&v_mat[i][j]);
	}
    }

    // initial case, put just one bunch in vase
    dp[1][1] = v_mat[1][1];
    for(int i = 1;i<=v;++i)
    {
	dp[1][i] = max(dp[1][i-1],v_mat[1][i]);
    }
    
    for(int i = 2;i<=f;i++)
    {
	for(int j = i;j<=v;++j) // notice the initialization of j
	{
	    //state is compose of bunch and vase
	    dp[i][j] = max(dp[i][j-1],dp[i-1][j-1]+v_mat[i][j]);
	}
    }
    

    printf("%d\n",dp[f][v]);


    return 0;
}
