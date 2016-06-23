#include "graph.h"
#include "string.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

//����
int LocateVex_M(MGraph G,VertexType u)
{
	int i = 0;
	for(;i < G.vexnum; ++i)
	{
		if(strcmp(u.name,G.vexs[i].name) == 0)
		{
			return i;
		}
	}
	return -1;//����ʧ��
}

//����ͼ
int IncInfo;
bool CreateGraph_M(MGraph &G)
{
	int i,j,k;
	int kind;
	VertexType v1,v2;
	VRType w;
	cout<<"����ͼ�����ͣ�����ͼ-0��������-1������ͼ-2��������-3��"<<endl;
	cin>>kind;
	G.kind = kind;
	cout<<"����ͼ�Ķ����������������Ƿ���������Ϣ����-1����-0��"<<endl;
	cin>>G.vexnum>>G.arcnum>>IncInfo;
	cout<<"����"<<G.vexnum<<"������ֵ������С��"<<MAX_NAME<<"���ַ���"<<endl;
	for(i=0;i < G.vexnum;++i)
	{
		cin>>G.vexs[i].name;
	}
	for(i = 0;i < G.vexnum;++i)
	{
		for(j=0;j<G.vexnum;++j)
		{
			if(!(G.kind%2))
			{
				G.arcs[i][j].adj = 0;
			}
			else
			{
				G.arcs[i][j].adj = MAX_VALUE;
			}
			G.arcs[i][j].info = NULL;
		}
	}

	for(k=0;k < G.arcnum;++k)
	{
		cout<<"�������"<<k+1<<"�����ĵĻ�β������1����ͷ������2��:";
		cin>>v1.name>>v2.name;
		i = LocateVex_M(G,v1);
		j = LocateVex_M(G,v2);
		if( i < 0 || j < 0 )
		{
			cout<<"����Ķ���1�򶥵�2�����ڣ�"<<endl;
			return false;
		}
		if(!(G.kind%2))
		{
			G.arcs[i][j].adj = 1;
		}
		else
		{
			cout<<"������Ȩֵ:";
			cin>>w;
			G.arcs[i][j].adj = w;
		}
		if(IncInfo)
		{
			cout<<"������û��������Ϣ��С��"<<MAX_INFO<<"���ַ���"<<endl;
			G.arcs[i][j].info = (char*)malloc((MAX_INFO)*sizeof(char));
			cin>>G.arcs[i][j].info;
		}
		if(G.kind > 1)
		{
			G.arcs[j][i] = G.arcs[i][j];
		}
	}
}

//��ȡͼ�����Ϊv�ĵĶ���ֵ
VertexType GetVer_M(MGraph G,int v)
{
	if(v > G.vexnum || v < 0)
	{
		exit(0);
	}
	else
	{
		return G.vexs[v];
	}
}

bool PutVer_M(MGraph &G,VertexType v,VertexType value)
{
	int locate = LocateVex_M(G,v);
	if(locate == -1)
	{
		cout<<"�ö��㲻����"<<endl;
		return false;
	}
	G.vexs[locate] = value;
	return true;
}


int FirstAdjVex_M(MGraph G,int v)
{
	int i;
	VRType j = 0;
	if( (G.kind % 2) )
	{
		j = MAX_VALUE;
	}
	for(i = 0;i < G.vexnum; ++i)
	{
		if(G.arcs[v][i].adj != j)
		{
			return i;
		}
	}
	return -1;
}


int NextAdjVex_M(MGraph G,int v,int w)
{
	int i;
	VRType j = 0;
	if((G.kind%2))
	{
		j = MAX_VALUE;
	}
	for(i = w + 1;i < G.vexnum;++i)
	{
		if(G.arcs[i][j].adj != j)
		{
			return i;
		}
	}
	return -1;
}


void InsertVex_M(MGraph &G,VertexType v)
{
	int i;
	VRType j = 0;
	if((G.kind%2))
	{
		j = MAX_VALUE;
	}
	G.vexs[G.vexnum] = v;
	for(i = 0;i <= G.vexnum; ++i)
	{
		G.arcs[G.vexnum][i].adj = j;
		G.arcs[i][G.vexnum].adj = j;
		G.arcs[G.vexnum][i].info = NULL;
		G.arcs[i][G.vexnum].info = NULL;
	}
	G.vexnum++;
}


bool InsertArc_M(MGraph &G,VertexType v,VertexType w)
{
	int i,v1,w1;
	v1 = LocateVex_M(G,v);
	w1 = LocateVex_M(G,w);
	if(v1 < 0 || w1<0)
	{
		return false;
	}
	++(G.arcnum);
	if(G.kind%2)
	{
		cout<<"������˱ߵ�Ȩֵ:"<<endl;
		cin>>G.arcs[v1][w1].adj;
	}
	else
	{
		G.arcs[v1][w1].adj = 1;
	}
	cout<<"�Ƿ��иñߵ������Ϣ����0-�ޣ�1-�У�"<<endl;
	cin>>i;
	if(i)
	{
		cout<<"������ñߵ������Ϣ��С��"<<MAX_INFO<<"���ַ�)"<<endl;
		cin>>G.arcs[v1][w1].info;
	}
	if(G.kind>1)
	{
		G.arcs[w1][v1] = G.arcs[v1][w1];
	}
	return true;
}


bool DeletArc_M(MGraph &G,VertexType v,VertexType w)
{
	int v1,w1;
	VRType j = 0;
	if(G.kind%2)
	{
		j = MAX_VALUE;
	}
	v1 = LocateVex_M(G,v);
	w1 = LocateVex_M(G,w);
	if(v1 < 0 || w1 < 0)
	{
		return false;
	}
	if(G.arcs[v1][w1].adj != j)
	{
		G.arcs[v1][w1].adj = j;
		if(G.arcs[v1][w1].info)
		{
			free(G.arcs[v1][w1].info);
			G.arcs[v1][w1].info = NULL;
		}
		if(G.kind >= 2)
		{
			G.arcs[w1][v1] = G.arcs[v1][w1];
		}
		--(G.arcnum);
	}
	return true;
}

bool DeletVex_M(MGraph &G,VertexType v)
{
	int i,j,k;
	k = LocateVex_M(G,v);
	if(k < 0)
	{
		return false;
	}
	for(i = 0;i < G.vexnum; ++i)
	{
		DeletArc_M(G,v,G.vexs[i]);
	}
	if(G.kind<2)
	{
		for(i = 0;i<G.vexnum;++i)
		{
			DeletArc_M(G,G.vexs[i],v);
		}
	}
	for(j=k+1;j<G.vexnum;++j)
	{
		G.vexs[j-1] = G.vexs[j];
	}
	for(i=0;i<G.vexnum;++i)
	{
		for(j=k+1;j<G.vexnum;++j)
		{
			G.arcs[j-1][i] = G.arcs[j][i];
		}

	}
	--(G.vexnum);
	return true;
}

void PrintGraph_M(MGraph G)
{
	int i,j;
	char s[10] = {"������"};
	char s1[4] = {"��"};
	switch(G.kind)
	{
	case 0:	strcpy(s,"����ͼ");
			strcpy(s1,"��");
			break;
	case 1: strcpy(s,"������");
			strcpy(s1,"��");
			break;
	case 2:	strcpy(s,"����ͼ");
			break;
	case 3:	break;
	default:break;
	}
	cout<<G.vexnum<<"������"<<G.arcnum<<"��"<<s1<<"��"<<s<<".���������ǣ�";
	for(i=0;i < G.vexnum;++i)
	{
		
		cout<<setw(5)<<GetVer_M(G,i).name;
	}
	cout<<endl<<"�ڽӾ���Ϊ��"<<endl;
	for(i=0;i<G.vexnum;++i)
	{
		for(j=0;j<G.vexnum;++j)
		{
			cout<<setw(8)<<G.arcs[i][j].adj;
		}
		cout<<endl;
	}
	if(IncInfo)
	{
		cout<<"���������Ϣ:"<<endl;
		if(G.kind < 2)
		{
			cout<<"��β ��ͷ ��"<<s1<<"����Ϣ��"<<endl;
		}
		else
		{
			cout<<"����1 ����2 ��"<<s1<<"����Ϣ��"<<endl;
		}
		for(i=0;i<G.vexnum;++i)
		{
			if(G.kind<2)
			{
				for(j=0;j<G.vexnum;++j)
				{
					if(G.arcs[i][j].info)
					{
						cout<<setw(5)<<G.vexs[i].name<<setw(5)<<G.vexs[j].name;
						cout<<setw(9)<<G.arcs[i][j].info<<endl;
					}
				}
			}
			else
			{
				for(j=i+1;j<G.vexnum;++j)
				{
					if(G.arcs[i][j].info)
					{
						cout<<setw(5)<<G.vexs[i].name<<setw(5)<<G.vexs[j].name;
						cout<<setw(9)<<G.arcs[i][j].info<<endl;
					}
				}
			}
		}
	}
}


void DestroyGraph_M(MGraph &G)
{
	int i;
	for(i=G.vexnum-1;i >= 0;--i)
	{
		DeletVex_M(G,G.vexs[i]);
	}
}


