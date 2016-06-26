#ifndef __TREE_H__
#define __TREE_H__

#define MAX_SON_SIZE 10					//��ຢ����
typedef char TElemType;					//�ڵ�ֵ����


typedef struct  CTNode
{
	TElemType data;						//�ڵ�ֵ
	struct CTNode *child[MAX_SON_SIZE];	//ָ���ӽڵ��ָ�룬�����MAX_SON_SIZE�����ӽڵ�
}CTNode,*CTree;

void InitTree(CTree &T);
void CreateTree(CTree &T,char *S);
void PreOrderTree(CTree T);
void PostOrderTree(CTree T);
void DestroyTree(CTree &T);

#endif