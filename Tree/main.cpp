#include <iostream>
#include <iomanip>
#include "tree.h"

using namespace std;

int main()
{
	CTree myTree;
	InitTree(myTree);
	CreateTree(myTree,"A(B(D,E(H,I),F),C(G))");
//ǰ�����
	cout<<"ǰ�����"<<endl;
	PreOrderTree(myTree);
//�������
	cout<<endl<<"�������"<<endl;
	PostOrderTree(myTree);
	DestroyTree(myTree);
}