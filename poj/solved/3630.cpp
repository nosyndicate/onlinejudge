/*
  trie
*/
#include<cstdio>
#include<cstring>
using namespace std;

#define RANGE 10
#define MAX 100010
struct Trie
{
    int num;
    bool word;
    Trie* children[RANGE];

};

// dynamic allocate node will cause time limited exceed
// have the use static method
Trie pool[MAX*10]; 
Trie* alloc;

int c_index(char c)
{
    if('0'<=c&&c<='9')
	return c-'0';
    else
	return -1;
}



bool insert(Trie* tree, char str[])
{
    Trie* p = tree;
    int length = strlen(str);
    for(int i = 0;i<length;++i)
    {
	int index = c_index(str[i]);
	if(p->children[index] == NULL) // add a new node
	{
	    // static allocate
	    p->children[index] = alloc++;
	    memset(p->children[index],0,sizeof(Trie));
	}	    
	p = p->children[index];
	p->num++;
	
	if(p->word) // if this is already a word, than we fail to insert
	    return false;
    }
    p->word = true; // insert the last character, so this is a complete word
    if(p->num>1)   // if this is prefix of some other string, we also fail
	return false;
    
    return true;
}

char str[12];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
	int n;
	bool fail = false;
	alloc = pool;
	Trie* tree = alloc++; // tree point the first address of the pool
	memset(tree,0,sizeof(Trie));
	scanf("%d",&n);
	for(int i = 0;i<n;++i)
	{
	    scanf("%s",str);	    
	    if(!fail)
	    {
		if(!insert(tree,str))
		{
		    fail = true;
		}
	    }
	    else
		continue;
	}
	if(fail)
	    printf("NO\n");
	else
	    printf("YES\n");

	// since this is static allocate, we don't need to free the memory
    }
    return 0;
}
