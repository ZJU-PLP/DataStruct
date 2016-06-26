#include "String.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>


using namespace std;

bool StrAssign_Sq(DSqString &S,char *chars)
{
	int length=0;				
	char *p = chars;			//��ʼָ��
	
	while (*p)				//�󴮳�
	{
		length++;			//���ȼ�
		p++;					//ָ�����
	}
	
	p = NULL;				//�������p�ÿ�
	free(p);					
	
	if (length == 0)			//�մ�
	{
		S.str = NULL;			//�ִ��ÿ�
		S.length = 0;			//���ȹ���
	}
	else						//�ǿմ�
	{
		//�����ڴ棬�����һ��������
		S.str = (char*)malloc((length+1)*sizeof(char));
		for (int i=0;i<length;i++) //�ַ�����
		{
			S.str[i] = chars[i];
		}
		S.str[length] = '\0';		//���Ľ�β��������
		S.length = length;		//�ִ����ȸ���
	}
	return true;
}

bool StrCopy_Sq(DSqString &S,DSqString T)
{
	if (!S.str)					//�����ƴ�Ϊ�����ͷ�
	{
		free(S.str);
	}

	if (0 == S.length)			//�ִ�����Ϊ0
	{
		S.str = NULL;				//�ִ��ÿ�
		S.length = 0;				//���ȹ���
	}
	//�����ڴ�Ҫ�����һ���ַ�λ�ã�������������
	S.str = (char*)malloc((T.length + 1) * sizeof(char));
	if (!S.str)
	{
		return false;
	}
	//�ִ�����
	for (int i = 0 ; i < T.length ;i++)
	{
		S.str[i] = T.str[i];
	}
	S.str[T.length] = '\0';     //��������
	S.length = T.length;
	return true;
}

int  StrLength_Sq(DSqString S)
{
	return S.length;
}

int StrCompare_Sq(DSqString S,DSqString T)
{
	int i = 0;
	while ((i < S.length) && (i < T.length))
	{
		if (S.str[i] > T.str[i])
		{
			return 1;			//S������T��
		}
		else if (S.str[i] < T.str[i])
		{
			return -1;			//T������S��
		}
		else
		{
		   i++;
		}
	}
	if (i<S.length)
	{
		return 1;				//S����T��
	}
	else if (i<T.length)
	{
		return -1;				//T����S��
	}
	else
	{
		return 0;				//�������
	}
}

bool StrConcat_Sq(DSqString &S,DSqString T)
{
	int i=0;
	if (T.length != 0)
	{
		//�ڴ����·���
		S.str = (ElemType*)realloc(S.str,(S.length + T.length + 1)*sizeof(ElemType));
		if (S.str == NULL)
		{
			return false;
		}
	}
	while (i < T.length)
	{
		S.str[S.length+i] = T.str[i];
		i++;
	}
	S.length += T.length;
	S.str[S.length] = '\0';
	return true;
}


bool SubString_Sq(DSqString S,DSqString &sub,int pos,int len)
{
	if (S.length < pos + len ||			//ȡ�Ӵ���Ϊ���ȷǷ�
		pos < 0 ||						//ȡ�Ӵ�λ�÷Ƿ�
		len < 0 ||						//ȡ�Ӵ����ȷǷ�
		pos > S.length - 1				//ȡ�Ӵ�λ�÷Ƿ�
		)
	{
		return false;
	}

	if (sub.str == NULL)					//�Ӵ��ռ��ͷ�
	{
		free(sub.str);
	}
	if (sub.length != 0)
	{
		sub.length = 0;
	}

	if (len != 0)
	{
		//Ϊ�Ӵ������ڴ�ռ�
		sub.str = (ElemType*)malloc((len + 1) * sizeof(ElemType));
		sub.length = len;
		if (sub.str == NULL)
		{
			return false;
		}

		for (int i = 0;i < len;i++)
		{
			sub.str[i] = S.str[pos + i];
		}
		sub.str[sub.length] = '\0';
	}
	else
	{
		sub.str = NULL;
		sub.length = 0;
	}
	return true;
}

bool Index_Sq(DSqString S,DSqString T,int &pos)
{
	int i = 0;
	int j = 0;
	while (i < S.length && j < T.length)
	{
		if (S.str[i] == T.str[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;   //iָ�����
			j = 0;
		}
	}
	if (j == T.length)
	{
		pos = i - T.length;
		return true;
	}
	else
		return false;
}


bool StrInsert_Sq(DSqString &S,int pos,DSqString T)
{
	int i = 0;
	if (pos < 0 || pos > S.length)
	{
		return false;
	}
	if (T.str != NULL)
	{
		S.str = (ElemType*)realloc(S.str,(S.length + T.length + 1)*sizeof(ElemType));
		if (S.str == NULL)
		{
			return false;
		}
		for (i=S.length-1;i>=pos;i--)
		{
			S.str[i+T.length] = S.str[i];
		}
		for (i=pos;i<T.length;i++)
		{
			S.str[i] = T.str[i - pos];
		}
		S.length += T.length;
		S.str[S.length] = '\0';
	}
	return true;
}


bool StrDelet_Sq(DSqString &S,int pos,int len)
{
	int i = 0;
	if (pos < 0 || pos > S.length)
	{
		return false;
	}
	for (i = pos + len;i <= S.length-1; i++)
	{
		S.str[i - len] = S.str[i];
	}
	S.str = (ElemType*)realloc(S.str,(S.length-len + 1)*sizeof(ElemType));
	S.length -= len;
	S.str[S.length] = '\0';
	return true;
}

void StrReplace_Sq(DSqString &S,DSqString T,DSqString V)
{
	int pos = 0;
	if (Index_Sq(S,T,pos))
	{
		StrDelet_Sq(S,pos,T.length);
		StrInsert_Sq(S,pos,V);
		pos += T.length;
		if (pos > S.length - T.length)
		{
			return;
		}
	}
}

void StrTravers_Sq(DSqString S)
{
	int i = 0;
	for (i = 0;i<S.length;i++)
	{
		cout<<setw(1)<<S.str[i];
	}
	cout<<endl;
}

void DestroyString_Sq(DSqString &S)
{
	free(S.str);
	S.str = NULL;
	S.length = 0;
}
