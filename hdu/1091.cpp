//http://acm.hdu.edu.cn/showproblem.php?pid=1091
#include <stdio.h>
int main()
{ 
    int a,b;
    while(scanf("%d %d",&a, &b))
        {
            if(a!=0||b!=0)
               printf("%d\n",a+b);
            else
               break;
        }
} 
