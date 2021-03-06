/*
	simulation
*/

#include<cstdio>
using namespace std;

int width[18];
int height[18];

int m,ww,hw;


void compute(int length)
{
    int c_w = 0,c_h = 0,p_w = 0,p_h = 0;
    for(int i = 0;i<length;++i)
    {
	// we can put it in the same row
	if(p_w+width[i]<=m)
	{
	    p_w = p_w + width[i];
	    if(p_w>c_w)
		c_w = p_w;
	    if(p_h+height[i]>c_h)
		c_h = height[i]+p_h;
	}
	// we need to start a new row
	else{
	    p_w = width[i];
	    p_h = c_h;
	    c_h = p_h + height[i];
	}
    }
    ww = c_w, hw = c_h;
}


int main()
{
    while(true)
    {
	scanf("%d",&m);
	if(m==0)
	    break;
	
	int index = 0;
	while(true)
	{
	    int h,w;
	    scanf("%d %d",&w,&h);
	    if(w==-1&&h==-1)
		break;
	    width[index]=w;
	    height[index++]=h;
	}
	
	compute(index);
	
	printf("%d x %d\n",ww,hw);
    }
    return 0;
}
