#include "stdafx.h"
#include"listnode.h"
#include"main.h"

int tpage = 0; //������Ŀ������ҳ��
void Pin();
void Pev(int);

void Ranks() { //����������
	tpage = (elist->size / 6) + 1;
	if (elist->size % 6 != 0) tpage++;
	Pin();
	_getch();
}

void Showevent(const PENode lastptr, int i) { //��ʾ��������Ŀ����
	int j = 0;
	if (i > 2) j = 10;
	gotoxy(hout, 2 + 26 * (i % 3), 4 + j);
	cout << "---" << Prtevent(lastptr->event) << "---";
	for (int k = 0; k < 6; k++) {
		gotoxy(hout, 2 + 26 * (i % 3), 6 + j + k);
		cout << "��" << k + 1 << "����" << Prtinst(lastptr->rank[k]);
	}
}

void Pin() { //��ʾԺ������ҳ��
	system("CLS");
	Grid();
	gotoxy(hout, 2, 1);
	cout << "���˶����ɼ�������\t\t\t\t0.���˵�    \t    2.��һҳ";
	PINode lastptr = ilist->head->next;
	gotoxy(hout, 32, 9);
	cout << "===����ɼ�===" << endl;
	for (int i = 1; i < 4; i++) {
		gotoxy(hout, 28, 9 + 2 * i);
		cout << "��" << i << "����" << Prtinst(lastptr->institute) << ' ' << lastptr->tscore << "��" << endl;
		lastptr = lastptr->next;
	}
	while (true) {
		char ch = _getch();
		switch (ch) {
		case '2':Pev(2); break;
		case '0':Ui(true); break;
		default:continue;
		}
	}
}

void Pev(int page) { //��ʾ������Ŀ����ҳ��
	system("CLS");
	Grid();
	if (page < 2) page = 2;
	else if (page > tpage) page = tpage;
	gotoxy(hout, 2, 1);
	if (page == tpage) cout << "���˶����ɼ�������\t\t\t\t0.���˵�  1.��һҳ";
	else cout << "���˶����ɼ�������\t\t\t\t0.���˵�  1.��һҳ  2.��һҳ";
	PENode lastptr = elist->head->next;
	for (int i = 0; i < (page - 2) * 6; i++) lastptr = lastptr->next;
	for (int j = 0; j < 6; j++) {
		Showevent(lastptr, j);
		lastptr = lastptr->next;
	}
	while (true) {
		char ch = _getch();
		switch (ch) {
		case '1':
			if (page == 2) Pin();
			else Pev(--page);
			break;
		case '0':
			Ui(true);
			break;
		case '2':
			if (page < tpage) Pev(++page);
		default:continue;
		}
	}
}