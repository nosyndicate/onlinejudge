//http://acm.hdu.edu.cn/showproblem.php?pid=2594
/*string match
use the kmp algorithm, to get the next array of the prefix string, then use the prefix string to match the 
suffix string, and get the final 'j' of the prefix string. 
*/

#include <cstdio>
#include <cstring>
#define RANGE 50005
char a[RANGE],b[RANGE];
int next[RANGE];

int Match(int la,int lb)
{
	int j = 0,max = 0;
	for(int i = 1;i <= lb;++i)
	{
		while((j > 0)&&(a[j+1] != b[i]))
			j = next[j];
		if(a[j+1] == b[i])
			j++;
	}
	return j;	//we only need the final j, which indicate at the end of the string B,
	            //how long could string A match the string B
}

void GetNextArray(int la,int lb)
{
	next[1] = 0;
	int j = 0;
	for(int i = 2;i <= la;++i)
	{
		while((j > 0)&&(a[j+1] != a[i]))
			j = next[j];
		if(a[j+1] == a[i])
			j++;
		next[i] = j;
	}
}

int main()
{
	while(scanf("%s%s",a+1,b+1)!=EOF)
	{
		int la = strlen(a+1);
		int lb = strlen(b+1);
		GetNextArray(la,lb);
		int length = Match(la,lb);
		if(length)
		{
			a[length+1] = '\0';//print the string, told by Xia Yang, avoid a loop for get the sub string.
			printf("%s %d\n",a+1,length);
		}
		else
			printf("0\n");
	}
	return 0;
}