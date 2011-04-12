//http://acm.hdu.edu.cn/showproblem.php?pid=1290
#include<stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
        printf("%d\n",(n*n*n+5*n+6)/6);
    return 0;
}

/*V£¨n£©=1/6(n^3+5n+6) */