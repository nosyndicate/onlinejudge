/*
  simulation
*/

#include<cstdio>
#include<cstring>
using namespace std;


int col;
char str[210];
char matrix[202][202]; // has to a bigger matrix, since col could equal to 1 
char buffer[210];


void reverse(int length)
{
    
    for(int i = 0;i<length/2;++i)
    {
	char temp = buffer[i];
	buffer[i] = buffer[length-1-i];
	buffer[length-1-i] = temp;
    }
}


int main()
{
    while(true)
    {
	scanf("%d",&col);
	if(col==0)
	    break;
	scanf("%s",str);

	int l = strlen(str),row = l/col;
	bool ltr = true;
	for(int i = 0;i<l;i+=col)
	{
	    if(ltr)
	    {
		strncpy(matrix[i/col],str+i,col);
		ltr = false;
	    }
	    else{
		strncpy(buffer,str+i,col);
		reverse(col);
		strncpy(matrix[i/col],buffer,col);
		ltr = true;
	    }

	}

	l = 0;
	for(int j = 0;j<col;++j)
	{
	    for(int i = 0;i<row;++i)
	    {
		buffer[l++] = matrix[i][j];
	    }
	}
	buffer[l]='\0';

	printf("%s\n",buffer);
    }
    return 0;
}
