//http://acm.hdu.edu.cn/showproblem.php?pid=1358
#include <cstdio>
#include <cstring>
#define RANGE 1000002
int length,cnt = 1;
char str[RANGE];
int next[RANGE];
void GetNextArray(char tpl[],int lt)
{
    int j = 0;
    next[1] = 0;
    for(int i = 2;i<=lt;++i)
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
    while(scanf("%d",&length),length)
    {
        
        scanf("%s",str+1);
        GetNextArray(str,length);
		printf("Test case #%d\n",cnt++);
        int pl = 1;
        for(int i = 2;i<=length;++i)
        {
			if((i%(i-next[i])==0)&&(i/(i-next[i])!=1))
				printf("%d %d\n",i,i/(i-next[i]));
        }
        printf("\n");
    }
    return 0;
}