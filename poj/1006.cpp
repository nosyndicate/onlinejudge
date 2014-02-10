#include <stdio.h>

int main()
{
    int t = 1;
    int p,e,i,d,ans;
    while(scanf("%d %d %d %d",&p,&e,&i,&d)!=EOF)
    {
	if(p==-1&&e==-1&&i==-1&d==-1)
	    break;
	while(true)
	{
	    if(p>=e&&p>=i)
	    {
		e+=28;i+=33;
	    }
	    if(e>p&&e>i)
	    {
		p+=23;i+=33;
	    }
	    if(i>p&&i>=e)
	    {
		p+=23;e+=28;
	    }
	    if(p==e&&e==i)
	    {
		ans = p;
		break;
	    }
	}
	printf("%d %d %d %d",p,e,i,ans);
	printf("Case %d: the next triple peak occurs in %d days.\n",t++, ans-d);
    }
    return 0;
}
