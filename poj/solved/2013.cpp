#include<cstdio>
#include<cstring>

using namespace std;

char matrix[20][30];
char transform[20][30];

int main()
{
    int n = 0,index=1;
    while(true)
    {
	scanf("%d",&n);
	if(n==0)
	    break;
	for(int i=0;i<n;++i)
	{
	    scanf("%s",matrix[i]);
	}

	printf("SET %d\n",index++);



	for(int i=0;i<n/2;++i)
	{
	    // first element of the pair
	    strcpy(transform[i],matrix[i*2]);
	    // second elemenf of the pair
	    strcpy(transform[n-1-i],matrix[i*2+1]);
	}
	
	// deal with not even case
	if(n%2!=0)
	{
	    strcpy(transform[(n/2)],matrix[n-1]);
	}
	
	for(int i=0;i<n;++i)
	{
	    printf("%s\n",transform[i]);
	}
    }
   
    return 0;
}
