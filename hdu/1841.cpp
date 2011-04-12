//http://acm.hdu.edu.cn/showproblem.php?pid=1841
/*kmp*/

#include <cstdio>
#include <cstring>
#define RANGE 1000005
char a[RANGE],b[RANGE];
int next[RANGE];

int Match(char tpl[],char super[],int ls,int lt)
{
	int j = 0,length = 0;
	for(int i=1;i<=ls;++i)
	{
		while((j>0)&&(tpl[j+1]!=super[i]))
			j = next[j];
		if(tpl[j+1]==super[i])
			j++;
		if(j==lt)
		{
			length = lt;
			return length;//add this clause to optimize the code;
		}
	}
	return j;//use return j>length?j:length before, which is so slow
}


void GetNextArray(char tpl[],int l)
{
	next[1]= 0;
	int j = 0;
	for(int i=2;i<=l;++i)
	{
		while((j>0)&&(tpl[j+1]!=tpl[i]))
			j = next[j];
		if(tpl[j+1]==tpl[i])
			j++;
		next[i] = j;
	}
}


int GetLength(int la,int lb)
{
	int lengthA = 0,lengthB = 0;
	GetNextArray(a,la);
	lengthA = Match(a,b,lb,la);
	GetNextArray(b,lb);
	lengthB = Match(b,a,la,lb);
	return lengthA>lengthB?lengthA:lengthB;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",a+1,b+1);
		int la = strlen(a+1);
		int lb = strlen(b+1);
		printf("%d\n",la+lb-GetLength(la,lb));
	}
	return 0;
}