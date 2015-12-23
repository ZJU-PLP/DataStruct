#include <iostream>
#include <iomanip>

#include "bitree.h"

using namespace std;

//ABD#G###CE##F##
void InitTree(BiTree &Bt)
{
	Bt = NULL;
}


int CreateTree(BiTree &Bt)
{
	TElemType a;
	cin>>a;
	if (a == '#')//����ڵ�ֵ��ʾΪ#���ʾ����Ϊ��
	{
		Bt = NULL;
	}
	else
	{
		Bt = (BiTree)malloc(sizeof(BiTNode));//����һ�����ڵ�ռ�
		if (!Bt)
		{
			exit(0);
		}
		Bt->data = a;			//�������ڵ��ֵ
		CreateTree(Bt->lchild);//�ݹ鴴��������
		CreateTree(Bt->rchild);//�ݹ鴴��������
	}
}


bool BiTreeEmpty(BiTree Bt)
{
	if (!Bt)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int BiTreeDepth(BiTree Bt)
{
	int lh,rh;
	if (!Bt)//�ж�����
	{
		return 0;
	}
	lh = BiTreeDepth(Bt->lchild);//�ݹ�������
	rh = BiTreeDepth(Bt->rchild);//�ݹ�������
	if (lh >= rh)//�������ֵ
	{
		return lh;
	}
	else
	{
		return rh;
	}
}


BiTree SearchBiTree(BiTree Bt,TElemType e)
{
	BiTree p;
	if (!Bt)//����
	{
		return NULL;
	}
	if (Bt->data == e)
	{
		return Bt;
	}
	//�������ǿգ�����������
	if (Bt->lchild)
	{
		p = SearchBiTree(Bt->lchild,e);//�ݹ����
		if (p)
		{
			return p;
		}
	}
	//�������ǿգ�����������
	if (Bt->rchild)
	{
		p = SearchBiTree(Bt->rchild,e);//�ݹ����
		if (p)
		{
			return p;
		}
	}
}

void PreOrderBiTree(BiTree Bt)
{
	if (Bt)
	{
		cout<<setw(2)<<Bt->data;
		PreOrderBiTree(Bt->lchild);
		PreOrderBiTree(Bt->rchild);
	}
}

void PostOrderBiTree(BiTree Bt)
{
	if (Bt)
	{
		PostOrderBiTree(Bt->lchild);
		PostOrderBiTree(Bt->rchild);
		cout<<setw(2)<<Bt->data;
	}
}

void DestroyBiTree(BiTree &Bt)
{
	if (Bt)
	{
		DestroyBiTree(Bt->lchild);
		DestroyBiTree(Bt->rchild);
		free(Bt);
		Bt = NULL;
	}
}