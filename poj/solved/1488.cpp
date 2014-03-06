/*
  relaxation
*/
#include<cstdio>

using namespace std;

int main()
{
    char c;
    bool first = true;
    while((c=getchar())!=EOF)
    {
	if(c=='"')
	{
	    if(first)
	    {
		printf("%s","``");
	    }
	    else
	    {
		printf("%s","''");
	    }
	    first = !first;
	}
	else
	    putchar(c);
    }
    return 0;
}
