#include<cstdio>
#include<cstring>

using namespace std;


double c_mat[32][32];
char c_n[32][100];

void read_name(int n)
{
    for(int i = 1;i<=n;++i)
    {
	scanf("%s",c_n[i]);
    }
}

int pos(char str[],int n)
{
    for(int i = 1;i<=n;++i)
    {
	if(!strcmp(str,c_n[i]))
	    return i;
    }
    return -1;
}


double max(double a, double b)
{
    if(a>b)
	return a;
    else 
	return b;
}

void arbitrage(int n)
{
    for(int k = 1;k<=n;++k)
    {
	for(int i=1;i<=n;++i)
	{
	    for(int j = 1;j<=n;++j)
	    {
		// using *MAX* here to maxify the arbitrage, not *MIN*
		c_mat[i][j] = max(c_mat[i][j],c_mat[i][k]*c_mat[k][j]);
	    }
	}
    }
}


int main()
{
    int index = 1;
    while(true)
    {
	int n;
	scanf("%d",&n);
	if(n==0)
	    break;
	// initialize matrix
	memset(c_mat,1.0,sizeof(c_mat));
	memset(c_n,0,sizeof(c_n));
	
	read_name(n);

	// start to fill the matrix
	int m;
	scanf("%d",&m);
	for(int i = 1;i<=m;++i)
	{
	    double value; char a[100],b[100];
	    scanf("%s %lf %s",a,&value,b);
	    int p1 = pos(a,n),p2 = pos(b,n);
	    c_mat[p1][p2] = value;
	}

	arbitrage(n);
	
	bool capable = false;

	for(int i = 1;i<=n;++i)
	{
	    if(c_mat[i][i]>1.0)
	    {
		capable = true;
		break;
	    }
	}

	if(capable)
	    printf("Case %d: Yes\n",index++);
	else
	    printf("Case %d: No\n",index++);
	
	
    }
    return 0;
}
