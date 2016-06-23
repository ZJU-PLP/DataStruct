#include <iostream>
#include <iomanip>
#include "queue_L.h"

using namespace std;

void main()
{
	ElemType num[] = {89,12,20,13,24,59,61,73,58,29};
	ElemType temp;
	LinkQueue myQueue;
	InitQueue_L(myQueue);

	for (int i = 0;i < 10;i++)
	{
		if (!EnQueue_L(myQueue,num[i]))
		{
			cout<<"���Ӵ���"<<endl;
			system("pause");
			return;
		}
		cout<<setw(3)<<num[i];
	}
	cout<<endl;
	for (int i=0;i < 10;i++)
	{
		if (!DeQueue_L(myQueue,temp))
		{
			cout<<"���Ӵ���"<<endl;
			system("pause");
			return;
		}
		cout<<setw(6)<<"����Ԫ��:"<<temp<<endl;
		if (!GetHead_L(myQueue,temp))
		{
			cout<<"��ȡ����Ԫ�ش���"<<endl;
		}
		else
			cout<<"��ǰ����Ԫ��:"<<temp<<endl;	
	}
	DestroyQueue_L(myQueue);
	cout<<endl;
	system("pause");
}