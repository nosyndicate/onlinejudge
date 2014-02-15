/*
  unknown
*/
#include<cstdio>
#include<cstring>
using namespace std;


// just counting the maximum access for each spot

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
	int n, corridor[202];
	scanf("%d",&n);
	memset(corridor,0,sizeof(corridor));
	for(int i = 0;i<n;++i)
	{
	    int start,end;
	    scanf("%d %d",&start,&end);

	    start = (start+1)/2;
	    end = (end+1)/2;
	    
	    if(start>end) // be careful of this case;
	    {
		int temp = end;
		end = start;
		start = temp;
	    }

	    for(int j = start;j<=end;++j)
	    {
		corridor[j]++;
	    }
	}
	int max = 0;
	for(int i = 1;i<201;++i)
	{
	    if(max<corridor[i])
		max = corridor[i];
	}
	
	printf("%d\n",max*10);
	
    }
    return 0;
}
