//http://acm.hdu.edu.cn/showproblem.php?pid=2048
#include <iostream>
using namespace std;
 int main()
 {
    int t,n;
    double a[21];
    a[1] = 0,a[2] = 1;
    for(int i = 3;i<21;++i)
        a[i] = (i-1)*(a[i-1]+a[i-2]);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        double sum = 1;
        for(int i = 1;i<=n;++i)
            sum*=i;
        double ret = a[n]/sum*100;
        printf("%.2f%s\n",ret,"%");
    }
    return 0;
 }