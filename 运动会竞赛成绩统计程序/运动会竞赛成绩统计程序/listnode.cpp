#include"stdafx.h"
#include"listnode.h"
#include "main.h"

ifstream ifs("sports.txt");

PENode Makeenode() { //���±�����Ŀ�����д������
	PENode node = new ENode;
	if (node != NULL) {
		string ch;
		if (ifs.eof()) return NULL; //�ж��Ƿ�����ļ���β
		getline(ifs, ch);
		node->event = ch; //д��������
		if (ch[0] == 'm') node->sex = m; //д���Ա���
		else node->sex = w;
		for (int i = 0; i <= 6; i++) { //д��������
			getline(ifs, ch, ' ');
			node->rank[i] = ch;
		}
		getline(ifs, ch);
		node->rank[7] = ch;
		node->next = NULL;
	}
	return node; //�����±�����Ŀ���
}

void Addscore(INode &node, const PENode lastptr, int score) { //������Ů�ӷ���
	if (score == 8) score++;
	if (lastptr->sex == m) node.mscore += score;
	else node.wscore += score;
}

void Makescore(INode node[], const EList *list) { //��Ժ�ӽ���з����ֵ
	PENode lastptr = list->head->next;
	while (lastptr != NULL) {
		for (int j = 0; j <= 7;j++) {
			if (lastptr->rank[j] == "xinxi") Addscore(node[xinxi], lastptr, 8 - j);
			else if (lastptr->rank[j] == "guofang") Addscore(node[guofang], lastptr, 8 - j);
			else if (lastptr->rank[j] == "ruanjian") Addscore(node[ruanjian], lastptr, 8 - j);
			else if (lastptr->rank[j] == "caiye") Addscore(node[caiye], lastptr, 8 - j);
			else if (lastptr->rank[j] == "gongguan") Addscore(node[gongguan], lastptr, 8 - j);
			else if (lastptr->rank[j] == "waiyu") Addscore(node[waiyu], lastptr, 8 - j);
			else if (lastptr->rank[j] == "shengke") Addscore(node[shengke], lastptr, 8 - j);
			else if (lastptr->rank[j] == "mazhe") Addscore(node[mazhe], lastptr, 8 - j);
		}
		lastptr = lastptr->next;
	}
	for (int j = 0; j <= 7; j++) node[j].tscore = node[j].mscore + node[j].wscore; //�����ܷ�
}

EList *Makeelist() { //����������Ŀ����
	EList *elist = (EList*)malloc(sizeof(EList));
	elist->size = 0;
	PENode head = (PENode)malloc(sizeof(ENode));
	if (elist != NULL) {
		if (head != NULL) {
			elist->head = head;
			head->next = NULL;
			PENode lastptr, newptr = Makeenode();
			lastptr = elist->head;
			while (newptr != NULL) {
				lastptr->next = newptr;
				elist->size++;
				lastptr = newptr;
				newptr = Makeenode();
			}
		}
	}
	return elist;
}

IList *Makeilist() { //����Ժ������
	IList *ilist = (IList*)malloc(sizeof(IList));
	PINode head = (PINode)malloc(sizeof(INode));
	if (ilist != NULL) {
		if (head != NULL) {
			ilist->head = head;
			head->next = NULL;
			PINode preptr = NULL, lastptr = NULL, newptr = NULL;
			for (int i = 0; i <= 7; i++) {
				newptr = &node[i];
				newptr->next = NULL;
				preptr = ilist->head;
				lastptr = ilist->head->next;
				if (lastptr == NULL) ilist->head->next = newptr;
				else {
					while ((lastptr != NULL) && (newptr->tscore < lastptr->tscore)) { //ʹ��㰴�����Ӵ�С����
						preptr = lastptr;
						lastptr = lastptr->next;
					}
					if (lastptr != NULL) {
						preptr->next = newptr;
						newptr->next = lastptr;
					}
					else preptr->next = newptr;
				}
			}
		}
	}
	return ilist;
}

void Destroyelist(EList *elist) { //��������
	PENode p, temp;
	p = elist->head;
	while (p != NULL) {
		temp = p->next;
		free(p);
		p = temp;
	}
	free(elist);
}