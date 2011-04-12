//http://acm.hdu.edu.cn/showproblem.php?pid=1009
#include <stdio.h>
#include <stdlib.h>
#define INF 1e10
#define N 1001
struct node{
	int j,f;
	double r;
};

node a[N];

int cmp(const void *a,const void *b){
	if(((node*)a)->r > ((node*)b)->r) return -1;
	else if(((node*)a)->r < ((node*)b)->r) return 1;
	else return 0;
}

int main()
{
	int i,j,k,m,n;
	double food,bean;

	while(scanf("%d%d",&m,&n),m!=-1)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].j,&a[i].f);
			a[i].r=(double)a[i].j/a[i].f;
		}

		qsort(a,n,sizeof(a[0]),cmp);

		food=m;
		bean=0;
		for(i=0;i<n;i++)
		{
			if(a[i].f<=food)
			{
				food-=a[i].f;
				bean+=a[i].j;
			}
			else
			{
				bean+=(food/a[i].f)*a[i].j;
				break;
			}
		}
		printf("%.3lf\n",bean);
	}
	return 0;
}



