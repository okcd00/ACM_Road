#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define N 500010
#define Maxn 51

char str[N*2], keyword[Maxn];
int head, tail;

struct node
{
	node *fail;
	node *next[26];
	int count;
	node() //init
	{
		fail = NULL;
		count = 0;
		for(int i = 0; i < 26; ++i)
			next[i] = NULL;
	}
}*q[N], *root;

void insert(char *str) //Insert into Trie
{
	int temp, len;
	node *p = root;
	len = strlen(str);
	for(int i = 0; i < len; ++i)
	{
		temp = str[i] - 'a';
		if(p->next[temp] == NULL)
			p->next[temp] = new node();
		p = p->next[temp];
	}
	p->count++;
}

void build_ac() //Init Fail_Pointer ,then BFS
{
	q[tail++] = root;
	while(head != tail)
	{
		node *p = q[head++]; //get the head
		node *temp = NULL;
		for(int i = 0; i < 26; ++i)
		{
			if(p->next[i] != NULL)
			{
				if(p == root) //If failed at 1st Letter, jump to root.
					p->next[i]->fail = root;
				else
				{
					temp = p->fail; //'Temp' to mark Fail-Pointer
					while(temp != NULL) //break if Find the Match Or Match-sequence is Null
					{
						if(temp->next[i] != NULL) //Find the Match
						{
							p->next[i]->fail = temp->next[i];
							break;
						}
						temp = temp->fail;
					}
					if(temp == NULL) //If Null,
						p->next[i]->fail = root;
				}
				q[tail++] = p->next[i]; //enqueue
			}
		}
	}
}

int query() //return appearance time
{
	int index, len, result;
	node *p = root; //Trie Entrance
	result = 0;
	len = strlen(str);
	for(int i = 0; i < len; ++i)
	{
		index = str[i] - 'a';
		while(p->next[index] == NULL && p != root) //jump to Fail_Pointer
			p = p->fail;
		p = p->next[index];
		if(p == NULL) p = root;
		node *temp = p; //Let temp record p's location. Then calc it.
		while(temp != root && temp->count != -1)
		{
			result += temp->count;
			temp->count = -1;
			temp = temp->fail;
		}
	}
	return result;
}

int main()
{
	int ncase, num;
	scanf("%d", &ncase);
	for(int _case=1;_case<=ncase;_case++)
	{
		head= tail = 0;
		root = new node();
		scanf("%d", &num);
		getchar();
		for(int i = 0; i < num; ++i)
		{
			gets(keyword);
			insert(keyword);
		}
		build_ac();
		scanf("%s", str);
		printf("%d\n", query());
	}
	return 0;
}
