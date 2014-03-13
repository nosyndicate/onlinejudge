/*
  simulation
*/
#include<cstdio>
using namespace std;

int coins[10001];

int main()
{
    int limit = 1,count = 0;
    for(int i = 1;i<=10000;++i)
    {
	if(count<limit)
	{
	    coins[i] = coins[i-1]+limit;
	    count++;
	}
	else
	{
	    limit++;
	    count = 1;
	    coins[i] = coins[i-1]+limit;
	}	
    }
    
    while(true)
    {
	int t;
	scanf("%d",&t);
	if(t==0)
	    break;
	
	printf("%d %d\n",t,coins[t]);
    }

}
