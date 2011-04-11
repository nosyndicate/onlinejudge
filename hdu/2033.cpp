//http://acm.hdu.edu.cn/showproblem.php?pid=2033
/*every body loves a+b problem*/
#include <cstdio>

int main()
{
	freopen("input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int ah,am,as,bh,bm,bs,anh,anm,ans;
		scanf("%d %d %d %d %d %d",&ah,&am,&as,&bh,&bm,&bs);
		ans = (bs + as) % 60;
		if(bs + as >= 60)
			bm++;
		anm  = (bm + am) % 60;
		if(bm + am >= 60)
			bh++;
		anh = bh + ah;
		printf("%d %d %d\n",anh,anm,ans);
	}
	return 0;
}