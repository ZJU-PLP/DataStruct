#include <iostream>
#include "stdlib.h"
#include "list_L.h"

using namespace std;

int main()
{
	LinkList head;
	ElemType x=0;
	int i,a[] = {6,8,16,2,34,56,7,10,22,45};
	InitList_L(head);
	for (i=1;i<=10;i++)
	{
		if (!ListInsert_L(head,i,a[i-1]))
		{
			cout<<"����ʧ�ܣ�"<<endl;
			system("pause");
			return 0;
		}
	}
	cout<<"ɾ��ǰ������Ϊ��"<<endl;
	ListTraverse_L(head);
	cout<<"��ǰ������Ϊ��"<<ListLengh_L(head)<<endl;
	cout<<"ɾ����4��Ԫ��"<<endl;
	ListDelete_L(head,4,x);
	cout<<"��ɾ����Ԫ����:"<<x<<endl;
	cout<<"ɾ���������Ϊ��"<<endl;
	ListTraverse_L(head);
	cout<<"��ǰ������Ϊ��"<<ListLengh_L(head)<<endl;
	DestroyList_L(head);
	system("pause");
	return 0;
}