#include <stdio.h>

int main()
{
    float c;
    while(scanf("%f",&c)!=EOF)
    {
	int num = 0;
	float length = 0;
	printf("the value of c is %f",c);
	if(c==0.00)
	    return 0;
	while(length < c)
	{
	    length += (1/(num + 2));
	    num++;
	}
	printf("%f\n",length);
    }
    return 0;
}
