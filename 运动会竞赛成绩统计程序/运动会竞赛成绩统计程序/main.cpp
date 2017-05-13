// �˶��Ὰ���ɼ�ͳ�Ƴ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "listnode.h"
#include "main.h"
#pragma warning(disable: 4996)

void Grid();
void Ui(bool);
void Score();
bool Searchfile();

EList *elist;
IList *ilist;
INode node[8] = { { 0,0,0,"xinxi" },{ 0,0,0,"guofang" },{ 0,0,0,"ruanjian" },{ 0,0,0,"caiye" },
{ 0,0,0,"gongguan" },{ 0,0,0,"waiyu" },{ 0,0,0 ,"shengke" },{ 0,0,0,"mazhe" } }; //��ʼ��Ժ�ӽṹ������
HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

int main(){
	bool flag = Searchfile();
	if (flag == true) {
		elist = Makeelist();
		Makescore(node, elist);
		ilist = Makeilist();
		Ui(true);
	}
	else Ui(false);
	return 0;
}

void gotoxy(HANDLE hout, int x, int y) { //��궨λ����
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hout, pos);
}

void Grid() { //�߿�
	gotoxy(hout, 0, 0);
	system("COLOR 2E");
	int a;
	cout << "������������������������������������������������������������������������������" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "������������������������������������������������������������������������������";
}

bool Searchfile() { //����sports.txt
	FILE *fp;
	fp = fopen("sports.txt", "r");
	if (fp == NULL) return false;
	else {
		char ch = '\0';
		fscanf_s(fp, "%c", &ch, 1);
		if (ch == '\0' || ch == ' ') return false;
		else return true;
	}
}

void Ui(bool flag) { //��ʾ�����溯��
	Grid();
	gotoxy(hout, 21, 2);
	cout << "��=====������ѧ��51���˶����=====��" << endl;
	gotoxy(hout, 25, 4);
	cout << "��=====�����ܳɼ�ͳ��=====��";
	gotoxy(hout, 30, 9);
	cout << "����������ѡ����Ŀ��" << endl;
	gotoxy(hout, 30, 11);
	cout << "1.�˶����÷����" << endl;
	gotoxy(hout, 30, 13);
	cout << "2.�˶����ɼ�����" << endl;
	gotoxy(hout, 30, 15);
	cout << "3.�ɼ���ѯ";
	gotoxy(hout, 30, 17);
	cout << "0.�˳�";
	gotoxy(hout, 2, 22);
	if (flag == true) cout << "sports.txt���ӳɹ���";
	else {
		cout << "sports.txt�����ڻ�Ϊ�գ���������˳�����";
		_getch();
		exit(0);
	}
	while (true) {
		char ch = _getch();
		switch (ch) {
		case '1':Score(node); break;
		case '2':Ranks(); break;
		case '3':Searchsco(); break;
		case '0':
			Destroyelist(elist);
			exit(0);
		default:continue;
		}
	}
}

string Prtinst(const string str) { //��ӡԺ������
	if (str == "xinxi") return "��ϢѧԺ";
	else if (str == "guofang") return "��������ѧԺ";
	else if (str == "ruanjian") return "���ѧԺ";
	else if (str == "caiye") return "������ұ��ѧԺ";
	else if (str == "gongguan") return "���̹���ѧԺ";
	else if (str == "waiyu") return "�����ѧԺ";
	else if (str == "shengke") return "�������ѧѧԺ";
	else if (str == "mazhe") return "���˼����ѧԺ";
	else return NULL;
}

string Prtevent(const string str) { //��ӡ������Ŀ����
	if (str == "m800") return "����800��";
	else if (str == "w800") return "Ů��800��";
	else if (str == "m4*100") return "����4��100�׽���";
	else if (str == "w4*100") return "Ů��4��100�׽���";
	else if (str == "m100") return "����100��";
	else if (str == "w100") return "Ů��100��";
	else if (str == "m1500") return "����1500��";
	else if (str == "wsitup") return "Ů����������";
	else if (str == "mhjump") return "��������";
	else if (str == "whjump") return "Ů������";
	else if (str == "mljump") return "������Զ";
	else if (str == "wljump") return "Ů����Զ";
	else if (str == "mtjump") return "����������";
	else if (str == "wtjump") return "Ů��������";
	else if (str == "mball") return "����������";
	else if (str == "wball") return "Ů��������";
	else if (str == "mmara") return "����������";
	else if (str == "wmara") return "Ů��������";
	else return NULL;
}