#ifndef _LISTNODE_H
#define _LISTNODE_H

typedef struct Institute { //����Ժ��������
	int mscore; //�ж��ܷ�
	int wscore; //Ů���ܷ�
	int tscore; //�����ܷ�
	string institute; //Ժ������
	struct Institute *next; //ָ����һ����ָ��
}INode, *PINode;

typedef struct Event{ //���������Ŀ������
	string event; //��Ŀ����
	int sex; //��Ŀ�Ա�
	string rank[8]; //��Ŀ��Ժ������
	struct Event *next; //ָ����һ����ָ��
}ENode, *PENode;

typedef struct { //����Ժ������
	PINode head; //����ͷ���
}IList;

typedef struct { //���������Ŀ����
	PENode head; //����ͷ���
	int size; //���������
}EList;

extern EList *Makeelist();
extern IList *Makeilist();
void Makescore(INode node[], const EList *);
void Destroyelist(EList *);
extern EList *elist;
extern IList *ilist;
extern INode node[8];

#endif