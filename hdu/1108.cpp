//http://acm.hdu.edu.cn/showproblem.php?pid=1108
include <stdio.h>
int main()
{
    int a,b,c;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
       for(c = a;c%b!=0;c+=a);
       printf("%d\n",c);
    }
    return 0;
}