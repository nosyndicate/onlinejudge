//http://acm.hdu.edu.cn/showproblem.php?pid=1032
#include <stdio.h>
int count[1000001];
int main()
{
	int begin,end;
	while(scanf("%d %d",&begin,&end)!=EOF)
	{
		printf("%d %d ",begin,end);//如果把这个放到循环结束，貌似无法通过，稀奇的很
		int max = 0;
		if(begin>end)
		{
			begin^=end;
			end^=begin;
			begin^=end;
		}
		for(int i = begin;i<=end;++i)
		{
			if(!count[i])
			{
				int n = i,time = 1;
				while(n!=1)
				{
					if(n%2==1)
						n = 3*n+1;
					else
						n/=2;
					time++;
				}
				count[i] = time;
			}
			if(count[i]>max)
				max = count[i];
		}
		printf("%d\n",max);
	}
	return 0;
}
/*
#include <iostream>
using namespace std;
#define MAXNUM 1000000 + 1
int result[MAXNUM];
int main()
{
    int beg,end,max,count,temp;
    while(cin>>beg>>end)
    {
        cout<<beg<<" "<<end<<" ";
        if(beg > end)
        {
	       temp = beg;beg = end;end = temp;
        }
        max = count = 0;
        for(int t = beg;t <= end;++t)
        {
            if(result[t])
                count = result[t];
            else
            {
                temp = t;
                count = 1;
                while(temp != 1)
                {
                    if(temp%2 == 0)
                        temp = temp/2;
                    else
                        temp = 3*temp + 1;
                    ++count;
                }
	          result[t] = count;
           }
           if(count > max)
                max = count;
        }
	    cout<<max<<endl;
    }
    return 0;
}
*/