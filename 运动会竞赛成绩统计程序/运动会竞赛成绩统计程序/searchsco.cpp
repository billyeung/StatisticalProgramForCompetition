#include"stdafx.h"
#include"listnode.h"
#include"main.h"

void Showinst(const string str) { //��ʾԺ����ϸ��Ϣ
	int irank = 1; //Ժ������ֵ
	system("CLS");
	Grid();
	PINode ilastptr = ilist->head->next;
	while (ilastptr->institute != str) {
		ilastptr = ilastptr->next;
		irank++;
	}
	gotoxy(hout, 2, 1);
	cout << "��ɼ���ѯ��\t\t\t\t\t    ===�������������һ��===";
	gotoxy(hout, 2, 3);
	cout << "===" << Prtinst(str) << "===";
	gotoxy(hout, 3, 5);
	cout << "�ж��ܷ֣�" << ilastptr->mscore << "��  |  Ů���ܷ֣�"<< ilastptr->wscore << "��";
	gotoxy(hout, 3, 7);
	cout << "�����ܷ֣�" << ilastptr->tscore << "�� �� ��" << irank << "��";
	gotoxy(hout, 30, 9);
	cout << "---������������---";
	PENode elastptr = elist->head->next;
	int num = 0;
	while (elastptr != NULL) {
		int i = 0, erank = 1;
		while (str != elastptr->rank[i++]) erank++; //�����Ժ���ڸ�������Ŀ������
		gotoxy(hout, 5 + (num / 6) * 23, 11 + num % 6 * 2);
		cout << Prtevent(elastptr->event) << "����" << erank << "��";
		elastptr = elastptr->next;
		num++;
	}
	_getch();
}

void Searchsco() { //��ѯ������
	while (true) {
		PINode lastptr = ilist->head->next;
		system("CLS");
		Grid();
		gotoxy(hout, 2, 1);
		cout << "��ɼ���ѯ��";
		gotoxy(hout, 24, 7);
		cout << "�� ���������ѯ��ѧԺ�Ĵ��룺";
		int i = 0;
		while (lastptr != NULL) {
			gotoxy(hout, 22 + i / 4 * 20, 9 + i % 4 * 2);
			cout << i + 1 << "." << Prtinst(lastptr->institute);
			lastptr = lastptr->next;
			i++;
		}
		gotoxy(hout, 62, 21);
		cout << "0.�������˵�";
	secho:
		char ch = _getch();
		if (ch == '0') break;
		else {
			switch (ch) {
			case '1':Showinst("xinxi"); break;
			case '2':Showinst("ruanjian"); break;
			case '3':Showinst("waiyu"); break;
			case '4':Showinst("guofang"); break;
			case '5':Showinst("gongguan"); break;
			case '6':Showinst("caiye"); break;
			case '7':Showinst("mazhe"); break;
			case '8':Showinst("shengke"); break;
			default:goto secho;
			}
		}
	}
	Ui(true);
}