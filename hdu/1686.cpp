//http://acm.hdu.edu.cn/showproblem.php?pid=1686
/*just use the template of kmp algorithm is fine*/
#include <cstdio>
#include <cstring>
char a[1000005];
char b[10005];
int next[10005];//careful, it is a array of int, not char!!

void GetNextArray(int la,int lb)
{
	next[1] = 0;
	int j = 0;
	for(int i = 2;i <= lb;++i)
	{
		while((j > 0)&&(b[j+1] != b[i]))
			j = next[j];
		if(b[j+1] == b[i])
			j++;
		next[i] = j;
	}
}

int Match(int la,int lb)
{
	int sum = 0;
	int j = 0;
	for(int i = 1; i <= la;++i)
	{
		while((j > 0) && (b[j+1] != a[i]))
			j = next[j];
		if(b[j+1] == a[i])
			j++;
		if(j == lb)
		{
			sum++;		
			j = next[j];
		}
	}
	return sum;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",b+1,a+1);
		int la = strlen(a+1);
		int lb = strlen(b+1);
		GetNextArray(la,lb);
		printf("%d\n",Match(la,lb));
	}
	return 0;
}