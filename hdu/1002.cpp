//http://acm.hdu.edu.cn/showproblem.php?pid=1002

#include <cstdio>
#include <cstring>
class BigInt
{
public:
	BigInt(){}
	BigInt(char num[])
	{
		strcpy(this->num,num);
		length = strlen(num);
		for(int i = 0;i<length;++i)
		{
			this->num[i]-='0';
		}
	}

	BigInt Add(BigInt b)
	{
		BigInt c;
		int ll,sl;
		char *shortStr,*longStr;
		if(this->length>b.length)
		{
			ll = this->length;
			sl = b.length;
			shortStr = b.num;
			longStr = this->num;
		}
		else
		{
			ll = b.length;
			sl = this->length;
			shortStr = this->num;
			longStr = b.num;
		}
		char strA[2002],strB[2002],strC[2002];
		memset(strA,0,sizeof(strA));
		memset(strB,0,sizeof(strB));
		memset(strC,0,sizeof(strC));
		memcpy(strA+1,longStr,ll);
		memcpy(strB+1+ll-sl,shortStr,sl);

		int carry = 0;
		for(int i = ll;i>=0;--i)
		{
			int r = strA[i] + strB[i];
			r += carry;
			carry = r/10;
			strC[i] = r%10;
		}
		if(strC[0]==0)
		{
			c.length = ll;
			memcpy(c.num,strC+1,c.length);
		}
		else
		{
			c.length = ll+1;
			memcpy(c.num,strC,c.length);
		}
		return c;
	}

	int length;
	char num[2000];
};


char numA[1002],numB[1002],numC[2002];

int main()
{
	freopen("input.txt","r",stdin);
	int t,cnt = 1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s %s",numA,numB);
		BigInt a(numA);
		BigInt b(numB);
		BigInt c = a.Add(b);
		for(int i = 0;i<c.length;++i)
			numC[i] = c.num[i] + '0';
		numC[c.length] = '\0';
		printf("Case %d:\n%s + %s = %s\n",cnt,numA,numB,numC);
		if(t)
			printf("\n");
		cnt++;
	}
	return 0;
}