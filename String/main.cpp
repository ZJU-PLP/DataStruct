#include "String.h"
#include <iostream>
#include <iomanip>

using namespace std;

void main()
{
	DSqString S1,S2,S3,S4;
	DSqString sub;
	int pos=10;
	StrAssign_Sq(S1,"child");
	StrAssign_Sq(S2,"children");
	StrAssign_Sq(S3,"chinese chair technology");
	StrCopy_Sq(S4,S1);
	//��ʼ�Ӵ�
	StrTravers_Sq(S1);
	StrTravers_Sq(S2);
	StrTravers_Sq(S3);
	StrTravers_Sq(S4);

	cout<<"��S1���ȣ�"<<endl<<StrLength_Sq(S1)<<endl;
	cout<<"��1�ʹ�2�Ƚϣ�"<<endl<<StrCompare_Sq(S1,S2)<<endl;
	StrConcat_Sq(S1,S2);
	cout<<"�ַ���S2ճ����S1��"<<endl;
	StrTravers_Sq(S1);
	cout<<"S3λ��Ϊ1����Ϊ5���Ӵ���"<<endl;
	SubString_Sq(S3,sub,1,5);
	StrTravers_Sq(sub);
	cout<<"�ַ���S1�в���S2��"<<endl;
	if(Index_Sq(S1,S2,pos))
	{
		cout<<pos<<endl;
	}
	else
	{
		cout<<"Index false"<<endl;
	}
	StrInsert_Sq(S3,0,S2);
	StrTravers_Sq(S3);
	cout<<"�Ӵ�ɾ��"<<endl;
	StrDelet_Sq(S3,0,16);

	cout<<"�ִ��滻"<<endl;
	StrReplace_Sq(S2,S1,S3);
	cout<<"�������ִ�:"<<endl;
	StrTravers_Sq(S1);
	StrTravers_Sq(S2);
	StrTravers_Sq(S3);
	StrTravers_Sq(S4);
	DestroyString_Sq(S1);
	DestroyString_Sq(S2);
	DestroyString_Sq(S3);
	DestroyString_Sq(S4);
	//system("pause");
}