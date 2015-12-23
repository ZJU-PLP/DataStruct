#include <iostream>
#include <iomanip>

#include "bitree.h"

using namespace std;

int main()
{
	BiTree myTree;           //ʵ����һ����
	InitTree(myTree);        //��ʼ����
	CreateTree(myTree);      //������
	PreOrderBiTree(myTree);  //ǰ�������
	DestroyBiTree(myTree);   //������
	return 0;
}