#ifndef __LIST_H__
#define __LIST_H__

#define LIST_INIT_SIZE 100  //˳���ĳ�ʼ�����������
#define LISTINCREAMENT 10	//(Ĭ��)�����ռ���

typedef int ElemType;		//�����ض���

typedef struct
{
	ElemType *elem;			//˳���Ԫ��
	int length;				//˳�����
	int listsize;			//��ǰ������������
	int increamentsize;		//�����ռ���(��ElemTypeΪ��λ)
}SqList;					//��̬˳���


//��ʼ�����Ա�
void InitList_Sq(SqList &L,int maxsize = LIST_INIT_SIZE,int incresize = LISTINCREAMENT);
//�������Ա���
int  ListLengh_Sq(SqList L);
//����Ԫ��e��λ��
int  LocateElem_Sq(SqList L,ElemType e);
//����Ԫ��
bool ListInsert_Sq(SqList &L,int i,ElemType e);
//ɾ��Ԫ��
bool ListDelete_Sq(SqList &L,int i,ElemType &e);
//����Ԫ��
void ListTraverse_Sq(SqList L);
//��ȡԪ��
bool GetElem_Sq(SqList L,int i,ElemType &e);

#endif


