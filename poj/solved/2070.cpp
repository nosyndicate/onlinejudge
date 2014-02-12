/*
	simulation
*/

#include<cstdio>
using namespace std;


double s,w,p;



bool wr()
{
    bool b_s = false,b_w = false,b_p = false;
    if(s<=4.5)
	b_s = true;
    if(w>=150)
	b_w = true;
    if(p>=200)
	b_p = true;
    return b_s&&b_w&&b_p;
}

bool lm()
{
    bool b_s = false,b_w = false,b_p = false;
    if(s<=6.0)
	b_s = true;
    if(w>=300)
	b_w = true;
    if(p>=500)
	b_p = true;
    return b_s&&b_w&&b_p;
}

bool qb()
{
    bool b_s = false,b_w = false,b_p = false;
    if(s<=5.0)
	b_s = true;
    if(w>=200)
	b_w = true;
    if(p>=300)
	b_p = true;
    return b_s&&b_w&&b_p;
}


int main()
{
    while(true)
    {
	scanf("%lf %lf %lf",&s,&w,&p);
	if(s==0&&w==0&&p==0)
	    break;

	bool a = wr();
	bool b = lm();
	bool c = qb();


	if(a)
	    printf("Wide Receiver ");
	if(b)
	    printf("Lineman ");
	if(c)
	    printf("Quarterback");

	if(!a&&!b&&!c)
	    printf("No positions");

	printf("\n");
	
    }
}
