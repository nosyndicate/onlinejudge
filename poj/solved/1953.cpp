#include<cstdio>

using namespace std;

int a[50]; // sequence ends with 0
int b[50]; // sequence ends with 1

int main()
{
    a[1]=b[1]=1;
    for(int i=2;i<50;++i)
    {
	a[i] = a[i-1]+b[i-1];
	b[i] = a[i-1];
    }


    int c,index=1;
    scanf("%d",&c);
    while(c--)
    {
	int length;
	scanf("%d",&length);
	printf("Scenario #%d:\n",index++);
	printf("%d\n\n",a[length]+b[length]);
    }
    return 0;
}
