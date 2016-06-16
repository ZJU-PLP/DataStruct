#include <iostream>
#include <iomanip>
#include "stack_L.h"

using namespace std;

void main()
{
	LinkStack myStack;
	ElemType num[10] = {0,1,2,3,4,5,6,7,8,9};
	ElemType temp;
	InitStack_L(myStack);
	cout<<"��ջ˳��:"<<endl;
	for (int i = 0;i < 10;i++)
	{
		if ( !Push_L(myStack,num[i]))
		{
			cout<<"��ջ����"<<endl;
			system("pause");
			return;
		}
		else
		{
			cout<<setw(3)<<num[i];
		}
	}
	cout<<endl;
	GetTop_L(myStack,temp);
	cout<<"��ǰջ��Ԫ��:"<<endl;
	cout<<temp<<endl;
	cout<<"��ջ˳��:"<<endl;
	for (int i = 0;i < 10;i++)
	{
		if (!Pop_L(myStack,temp))
		{
			cout<<"��ջ����"<<endl;
			system("pause");
			return;
		}
		else
		{
			cout<<setw(3)<<temp;
		}
		
	}
	cout<<endl;
	DestroyStack_L(myStack);
	system("pause");
}