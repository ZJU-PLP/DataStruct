#include <iostream>
#include <iomanip>
#include "queue_Sq.h"

using namespace std;

void main()
{
	ElemType num[]={21,1,2,3,4,5,6,7,8,9};
	ElemType temp;
	SqQueue myQueue;
	InitQueue_Sq(myQueue,5,9);
	cout<<"����˳��:"<<endl;
	for (int i=0;i < 10;i++)
	{
		if (!EnQueue_Sq(myQueue,num[i]))
		{
			cout<<"���Ӵ���"<<endl;
			system("pause");
			return;
		}
		cout<<setw(3)<<num[i];
	}
	cout<<endl;

	if (!GetHead_Sq(myQueue,temp))
	{
		cout<<"��ȡ����Ԫ�ش���"<<endl;
	}
	else
		cout<<"��ǰ����Ԫ��:"<<temp<<endl;	

	cout<<"����˳��:"<<endl;
	for (int i=0;i < 10;i++)
	{
		if (!DeQueue_Sq(myQueue,temp))
		{
			cout<<"���Ӵ���"<<endl;
			system("pause");
			return;
		}
		cout<<setw(3)<<temp;
	}
	DestroyQueue_Sq(myQueue);
	cout<<endl;
	system("pause");
}