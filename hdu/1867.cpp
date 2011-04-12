//http://acm.hdu.edu.cn/showproblem.php?pid=1867
/*一次AC，虽说之前看了网上讲的思路，不过还是蛮有成就感的*/

#include <cstdio>
#include <cstring>
#define RANGE 100002
char a[RANGE],b[RANGE];
int next[RANGE];

int Match(char tpl[],char super[],int lt,int ls)
{
	int j = 0;
	for(int i = 1;i<=ls;++i)
	{
		while((j>0)&&(tpl[j+1]!=super[i]))
			j = next[j];
		if(tpl[j+1]==super[i])
			j++;
		if(j==lt)
			j = next[j];
	}
	return j;
}

void GetNextArray(char tpl[],int l)
{
	int j = 0;
	next[1] = 0;
	for(int i = 2;i<=l;++i)
	{
		while((j>0)&&(tpl[j+1]!=tpl[i]))
			j = next[j];
		if(tpl[j+1]==tpl[i])
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
		GetNextArray(a,la);
		int ba = Match(a,b,la,lb);
		GetNextArray(b,lb);
		int ab = Match(b,a,lb,la);
		if(ab>ba)
			printf("%s%s\n",a+1,b+1+ab);
		else if(ba>ab)
			printf("%s%s\n",b+1,a+1+ba);
		else
		{
			int cr = strcmp(a+1,b+1);
			if(cr>0)
				printf("%s%s\n",b+1,a+1+ab);
			else if(cr<0)
				printf("%s%s\n",a+1,b+1+ba);
			else
				printf("%s\n",a+1);				
		}
	}
	return 0;
}