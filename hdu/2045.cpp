//http://acm.hdu.edu.cn/showproblem.php?pid=2045
#include <stdio.h>
int main()
{
    __int64 a[51];
    a[1] = 3,a[2] = 6,a[3] = 6;
    for(int i = 4;i<51;++i)
    {
        a[i] = a[i-1]+2*a[i-2];
    }
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%I64d\n",a[n]);
    }
    return 0;
}
/*
1.��ǰn-1�Ϸ�������β��ͬ������1��ʱ��ֻ��1�ַ�����
2.��ǰn-1���Ϸ�������1��ʱ�Ϸ�����ֻ����Ϊ��β��ͬ����Ĳ��Ϸ�������ǰn-2�ض��Ϸ�����ʱ��n���������2�ַ�����
3.f(1)=3;f(2)=6;f(3)=6.
*/