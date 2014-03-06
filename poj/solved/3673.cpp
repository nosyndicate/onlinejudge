/*
  relaxation
*/
#include<cstdio>
#include<cstring>
using namespace std;

char a[110],b[110];

int main()
{
    scanf("%s %s",a,b);
    
    int la = strlen(a);
    int lb = strlen(b);

    long long ans = 0;
    for(int i = 0;i<la;++i)
    {
	for(int j = 0;j<lb;++j)
	{
	    ans += ((a[i]-'0')*(b[j]-'0'));
	}
    }

    printf("%lld\n",ans);

    return 0;
}
