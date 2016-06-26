#include <iostream>
#include <iomanip>
#include "tree.h"

using namespace std;

#define MS 10

void InitTree(CTree &T)
{
	T = NULL;
}

//A(B(D,E(H,I),F),C(G))
void CreateTree(CTree &T,char *S)
{
	CTree stack[MS],p;
	int i=0,d[MS];
	int top = -1;
	while (S[i])
	{
		switch(S[i])
		{
		case ' ': break;
		case '('://ѹջ
			top++;
			stack[top] = p;
			d[top] = 0;
			break;
		case ')'://��ջ
			top--;
			break;
		case ',':
			d[top]++;
			break;
		default:
			if (!(p=(CTree)malloc(sizeof(CTNode))))
			{
				exit(1);
			}
			p->data = S[i];
			for (int i = 0;i < MAX_SON_SIZE;i++)
			{
				p->child[i] = NULL;
			}
			if (!T)
			{
				T = p;
			}
			else
			{
				stack[top]->child[d[top]] = p;
			}
			break;
		}
		i++;
	}
}

//ǰ�����
void PreOrderTree(CTree T)
{
	if (T)
	{
		cout<<T->data;
		for (int i=0;i<MAX_SON_SIZE;i++)
		{
			PreOrderTree(T->child[i]);
		}
	}
}

//�������
void PostOrderTree(CTree T)
{
	if (T)
	{
		for (int i=0;i<MAX_SON_SIZE;i++)
		{
			PostOrderTree(T->child[i]);
		}
		cout<<T->data;
	}
}


void DestroyTree(CTree &T)
{
	if (T)
	{
		for(int i=0;i<MAX_SON_SIZE;i++)
		{
			DestroyTree(T->child[i]);
		}
		free(T);
		T = NULL;
	}
}