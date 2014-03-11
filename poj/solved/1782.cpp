/*
  simulation
*/
#include<cstdio>
#include<cstring>
using namespace std;

char str[10010];
char output[10010];
char buffer[100];
int rep = 0;
int b_i = 0;

void flush()
{
    int ol = strlen(output);
    int bl = strlen(buffer);
    if(rep>0)
    {
	output[ol] = rep+'0';
	output[ol+1] = buffer[0];
    }
    else if(rep==0&&bl>=1)
    {
	output[ol] = '1';
	for(int i = 0;i<bl;++i)
	{
	    output[ol+1+i] = buffer[i];
	}
	output[ol+1+bl] = '1';
    }
    memset(buffer,0,sizeof(buffer));
    b_i = 0;
}


int main()
{
    while(gets(str)!=NULL) // use gets for reading space
    {
	memset(buffer,0,sizeof(buffer));
	memset(output,0,sizeof(output));
	int length = strlen(str);
	for(int i = 0;i<length;++i)
	{
	    char c = str[i];
	    char lookahead = str[i+1];
	    // consecutive characters here
	    if(c==lookahead)
	    {
		//if we start with a new consecutive sequence. flush the buffer
		if(rep==0)
		    flush();
		rep++; // incf repetition
		if(buffer[0]==0)//if we didn't record it, record it
		    buffer[0] = c;
		if(rep==9)
		{
		    flush();
		    rep = 0;
		}
	    }
	    else if(c!=lookahead)
	    {
		// end of conseutive characters
		if(rep!=0)
		{
		    rep++; // add this character
		    flush();// make it to output
		    rep = 0; // reset all the temp variable
		}
		// no consecutive repetitions
		else if(rep==0)
		{
		    if(c=='1')
			buffer[b_i++] = '1';
		    buffer[b_i++] = c;
		}
	    }
	}
	flush();// don't forget to flush at the last time
	printf("%s\n",output);
    }
    return 0;
}
