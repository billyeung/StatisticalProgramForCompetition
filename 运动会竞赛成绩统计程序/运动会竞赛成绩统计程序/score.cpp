#include"stdafx.h"
#include"listnode.h"
#include"main.h"

void Score(INode node[]) { //�÷��������
	system("CLS");
	Grid();
	gotoxy(hout, 2, 1);
	cout << "���˶����÷������";
	gotoxy(hout, 3, 4);
	cout << "��ϢѧԺ �� �ж��ܷ֣�" << node[xinxi].mscore << "�� Ů���ܷ֣�" << node[xinxi].wscore << "�� �����ܷ֣�" << node[xinxi].tscore << "��";
	gotoxy(hout, 3, 6);
	cout << "���ѧԺ �� �ж��ܷ֣�" << node[ruanjian].mscore << "�� Ů���ܷ֣�" << node[ruanjian].wscore << "�� �����ܷ֣�" << node[ruanjian].tscore << "��";
	gotoxy(hout, 3, 8);
	cout << "�����ѧԺ �� �ж��ܷ֣�" << node[waiyu].mscore << "�� Ů���ܷ֣�" << node[waiyu].wscore << "�� �����ܷ֣�" << node[waiyu].tscore << "��";
	gotoxy(hout, 3, 10);
	cout << "��������ѧԺ �� �ж��ܷ֣�" << node[guofang].mscore << "�� Ů���ܷ֣�" << node[guofang].wscore << "�� �����ܷ֣�" << node[guofang].tscore << "��";
	gotoxy(hout, 3, 12);
	cout << "���̹���ѧԺ �� �ж��ܷ֣�" << node[gongguan].mscore << "�� Ů���ܷ֣�" << node[gongguan].wscore << "�� �����ܷ֣�" << node[gongguan].tscore << "��";
	gotoxy(hout, 3, 14);
	cout << "������ұ��ѧԺ �� �ж��ܷ֣�" << node[caiye].mscore << "�� Ů���ܷ֣�" << node[caiye].wscore << "�� �����ܷ֣�" << node[caiye].tscore << "��";
	gotoxy(hout, 3, 16);
	cout << "���˼����ѧԺ �� �ж��ܷ֣�" << node[mazhe].mscore << "�� Ů���ܷ֣�" << node[mazhe].wscore << "�� �����ܷ֣�" << node[mazhe].tscore << "��";
	gotoxy(hout, 3, 18);
	cout << "������ѧ�뽡��ѧԺ �� �ж��ܷ֣�" << node[shengke].mscore << "�� Ů���ܷ֣�" << node[shengke].wscore << "�� �����ܷ֣�" << node[shengke].tscore << "��";
	gotoxy(hout, 27, 22);
	cout << "===��������������˵�===";
	_getch();
	Ui(true);
}