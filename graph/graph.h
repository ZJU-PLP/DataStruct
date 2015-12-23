#ifndef __GRAPH_H__
#define __GRAPH_H__

#define MAX_VALUE 32767			//��������󣬱�ʾȨ���ֵ
#define MAX_VERTEX_NUM 100		//��󶥵����
#define MAX_NAME 9				//�������Ƶ��ַ�����󳤶�+1
#define MAX_INFO 20				//���ߵ������Ϣ�ַ�����󳤶�+1

typedef char *InfoType;			//�ߵ������Ϣ����
typedef int VRType;				//���嶥���ϵ����Ϊ����
typedef struct
{
	char name[MAX_NAME];		
}VertexType;					//������Ϣ����

//����Ϣ�ṹ
typedef struct
{
	VRType adj;			//������ϵ
	InfoType info;		//�û������Ϣ��ָ��
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];	//�ڽӾ���

//ͼ����Ϣ�ṹ
typedef struct
{
	VertexType vexs[MAX_VERTEX_NUM];	//��������
	AdjMatrix arcs;						//�ڽӾ���
	int vexnum,arcnum;					//ͼ�ĵ�ǰ�������ͻ���
	int kind;							//ͼ�������־
}MGraph;								//ͼ�Ľṹ


int LocateVex_M(MGraph G,VertexType u);	//��ͼ�в��Ҷ���ֵΪu�Ķ���
bool CreateGraph_M(MGraph &G);
VertexType GetVer_M(MGraph G,int v);
bool PutVer_M(MGraph &G,int v);
int FirstAdjVex_M(MGraph G,int v);
int NextAdjVex_M(MGraph G,int v,int w);
void InsertVex_M(MGraph &G,VRType v);
bool InsertArc_M(MGraph &G,VertexType w);
bool DeletArc_M(MGraph &G,VertexType v,VertexType w);
bool DeletVex_M(MGraph &G,VertexType v);
void PrintGraph_M(MGraph G);
void DestroyGraph_M(MGraph &G);


#endif