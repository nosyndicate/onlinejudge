/*
  dynamic programming 
  floyd warshall
 */
#include<cstdio>
#include<cstring>
using namespace std;


int c_mat[110][110];
int MAX = 999999;

int min(int a,int b)
{
    if(a>b)
	return b;
    else 
	return a;
}


void init_graph()
{
    for(int i = 0;i<110;++i)
    {
	for(int j = 0;j<110;++j)
	{
	    if(i==j)
		c_mat[i][j];
	    else
		c_mat[i][j] = MAX;
	}
    }
}


void all_pair_shortest(int n)
{
    for(int k=1;k<=n;++k)
    {
	for(int i = 1;i<=n;++i)
	{
	    for(int j = 1;j<=n;++j)
	    {
		// since we are computing iteratively, we just use our original matrix
		c_mat[i][j] = min(c_mat[i][j],c_mat[i][k]+c_mat[k][j]);
	    }
	}
    }
}


void scan_matrix(int n,int* p,int* l)
{
    int min_dis[110] = {MAX};
    for(int i = 1;i<=n;++i)
    {
	int temp = -1;
	for(int j = 1;j<=n;++j)
	{
	    if(c_mat[i][j]>temp)
	    {
		temp = c_mat[i][j];
	    }
	}
	min_dis[i] = temp;
    }
    int index=-1,value=MAX;
    for(int i = 1;i<=n;++i)
    {
	if(min_dis[i]<value)
	{
	    value = min_dis[i];
	    index = i;
	}    
    }
    *p = index,*l = value;
}


int main()
{
    int sn;
    while(true)
    {
	scanf("%d",&sn);
	if(sn==0)
	    break;

	init_graph(); // initialize graph every time
	int index = 1;
	while(index<=sn)
	{
	    int c_n;
	    scanf("%d",&c_n);
	    for(int i = 0;i<c_n;++i)
	    {
		int c,t;
		scanf("%d %d",&c,&t);
		c_mat[index][c] = t;
	    }
	    index++;
	}

	all_pair_shortest(sn);
	int p,l;
	scan_matrix(sn,&p,&l);
	if(l==MAX)
	    printf("disjoint\n");
	else
	    printf("%d %d\n",p,l);


    }
    return 0;
}
