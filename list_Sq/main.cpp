#include "stdlib.h"
#include "iostream"
#include "list_Sq.h"

using namespace std;

void main()
{
	SqList mylist;
	int i,x,a[] = {6,8,16,2,34,56,7,10,22,45};
	InitList_Sq(mylist,50,10);
	for (i=0;i<10;i++)
	{
		if (!ListInsert_Sq(mylist,i,a[i]))
		{
			cout<<"����ʧ��"<<endl;
			return;
		}
	}
	cout<<"��ǰǰ��˳���Ϊ��";
	ListTraverse_Sq(mylist);
	system("pause");
}