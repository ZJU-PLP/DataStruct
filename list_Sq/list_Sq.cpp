#include "list_Sq.h"
#include "string.h"							//memset���ڿ�
#include "stdlib.h" 
#include "iostream"
#include "iomanip"
using namespace std;

void InitList_Sq(SqList &L,int maxsize,int incresize)
{
	L.elem = new ElemType[maxsize];			//�����ƶ���С�Ŀռ�
	if (!L.elem)
	{
		exit(1);							//����ʧ�����˳�
	}
	L.length = 0;							//���Ա��ʼ����Ϊ0
	L.listsize = maxsize;					//���Ա������󳤶�
	L.increamentsize = incresize;			//���Ա�����ӳ���
}


int  ListLengh_Sq(SqList L)					
{
	return L.length;						//�������Ա�ĳ���
}


//�������Ա���ֵΪe��Ԫ��λ��
int  LocateElem_Sq(SqList L,ElemType e)		
{
	for (int i = 0;i<L.length;i++)			//�����Ա�ı�ͷ����󳤶Ȳ���
	{
		if (L.elem[i] == e)					
		{
			return i;						//���ҵ��򷵻ظ�Ԫ��λ��
		}
	}
	return -1;								//δ�ҵ���Ԫ�أ��򷵻�-1
}


//�����Ա����Ԫ��
bool ListInsert_Sq(SqList &L,int i,ElemType e)
{
	int j;
	if (i < 0 || i > L.length)				//����λ�÷Ƿ����˳�
	{
		return false;
	}
	
	if (L.length > L.listsize)				//�����Ա�ĳ��ȴ������Ա����������
	{
		//����elemָ��Ŀ��÷�Χ���������Ա���
		L.elem = (ElemType*)realloc(L.elem,(L.listsize + L.increamentsize) * sizeof(ElemType));
		if (!L.elem)	//������ʧ�ܣ����˳�
		{
			exit(1);
		}
		L.listsize += L.increamentsize;		//���±�
	}
	for (j = L.length;j > i;j++)			//����Ԫ�ؼ��Ժ�Ԫ�������ƶ�
	{
		L.elem[j] = L.elem[j-1];
	}
	L.elem[i] = e;							//����Ԫ��
	L.length++;								//����1
	return true;
}


bool ListDelete_Sq(SqList &L,int i,ElemType &e)
{
	int j;
	if (i < 0 || i >= L.length)				//��ɾ��λ�÷Ƿ�,�˳�
	{
		return false;
	}
	if (L.length <= 0)						//���Ա�Ϊ�գ��˳�
	{
		return false;
	}
	e = L.elem[i];							//��ɾ��ֵת��
	for (j = i + 1;j <= L.length - 1;j++)	
	{
		L.elem[j-1] = L.elem[j];			//ɾ��Ԫ���Ժ��Ԫ�������ǰ�ƶ�
	}
	L.length--;								//���Ա��ȼ�1
	return true;
}


void ListTraverse_Sq(SqList L)
{
	int i;
	for (i = 0;i < L.length; i++)			//�����Ա��ͷ����β�������Ԫ��
	{
		cout<<setw(5)<<L.elem[i];
	}
	cout<<endl;
}

//��ȡλ��Ϊi�����Ա���Ԫ��
bool GetElem_Sq(SqList L,int i,ElemType &e)
{
	if (i<0 || L.length)					//����λ�÷Ƿ����˳�
	{
		return false;
	}
	if (L.length <= 0)						//���Ա�Ϊ�գ��˳�
	{
		return false;
	}
	e = L.elem[i];							//��ȡλ��Ϊi��Ԫ��
	return true;
}

