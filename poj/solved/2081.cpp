#include<cstdio>
using namespace std;


// b array could be a lot of bigger than a array

int a[500001]={0};
int b[5000000]={0};

int k;

int main()
{
    a[0] = 0;

    for(int i = 1;i<500001;++i)
    {
	int result = a[i-1]-i;
	if(result>0&&!b[result])
	{
	    b[result]=1;
	    a[i] = result;
	}
	else
	{
	    a[i]=a[i-1]+i;
	    b[a[i]]=1;
	}

    }

    while(true)
    {
	scanf("%d",&k);
	if(k==-1)
	    break;
	printf("%d\n",a[k]);
    }
    return 0;
}
