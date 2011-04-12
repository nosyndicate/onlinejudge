//http://acm.hdu.edu.cn/showproblem.php?pid=2042
#include <stdio.h>
int main()
{
   int n;
   scanf("%d",&n);
   while(n--)
   {
      int t,ret = 3;
      scanf("%d",&t);
      for(int i = 0;i<t;++i)
      {
         ret = (ret-1)*2;
      }
      printf("%d\n",ret);
   }
   return 0;
}