/*
  trie
  string
*/

#include<cstdio>
#include<cstring>
using namespace std;

#define RANGE 26

struct Trie
{
    int val;
    bool word;
    Trie* children[RANGE];

    Trie();
};

Trie::Trie()
{
    for(int i = 0;i<RANGE;++i)
    {
	this->children[i] = NULL;
    }
    this->val = 0;
    this->word = false;
}


char str[1001][30];
char output[30];

int c_index(char a)
{
    if('a'<=a&&a<='z')
	return a-'a';
    else
	return -1;
}



void insert(Trie* tree,char str[])
{
    Trie* p = tree;
    int length = strlen(str);
    for(int i = 0;i<length;++i)
    {
	int index = c_index(str[i]);
	if(p->children[index]==NULL)
	    p->children[index] = new Trie();

	p = p->children[index];
	p->val++;
    }
    // insert the last character, so this is a complete word
    p->word=true;
}




char* search(Trie* tree, char str[])
{
    memset(output,0,sizeof(output));
    Trie* p = tree;
    int j = 0,length = strlen(str);

    for(int i = 0;i<length;++i)
    {
	int index = c_index(str[i]);
	if(p->children[index]!=NULL)
	{
	    output[j++] = str[i];
	    p = p->children[index];
	    if(p->val==1)   // if we reach some prefix, then we return result
		return output;
	}
    }
    // if we run out of the characters, then we simply return the whole string
    return output;
}



void clear(Trie* tree)
{
    Trie* root = tree;
    for(int i = 0;i<RANGE;++i)
    {
	if(tree->children[i]!=NULL)
	{
	    clear(tree->children[i]);
	}
    }
    delete root;
}


int main()
{
    // create a new trie
    Trie* tree = new Trie();
    int k = 0;
    while(scanf("%s",str[k])!=EOF)
    {
	insert(tree,str[k]);
	k++;
    }
    
    
    
    for(int i = 0;i<k;++i)
    {
	printf("%s ",str[i]);
	printf("%s\n",search(tree,str[i]));
    }

    clear(tree);
}
