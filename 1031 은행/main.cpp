#include <iostream>
using namespace std;
#include <conio.h>
#include "account.h"
#include "bank.h"

void run(bank *bb)
{
	while (true)
	{
		system("cls");
		cout << "�ҷ������࿡ ���Ű� ȯ���մϴ�." << endl;
		cout << "===============================" << endl;
		cout << "[1] �ű԰���" << endl;
		cout << "[2] ȸ����ȸ" << endl;
		cout << "[3] �Ա�" << endl;
		cout << "[4] ���" << endl;
		cout << "[5] ��������" << endl;
		cout << "[6] ����" << endl;
		cout << "===============================" << endl;

		switch (_getch())
		{
		case'1': bb->insert();		break;
		case'2': bb->printall();    break;
		case'3': bb->saving();		break;
		case'4': bb->withdraw();    break;
		case'5': bb->delete_account(); break;
		case'6': bb->byebye();      return;
		}
		system("pause");
	}
}

int main()
{
	bank bb;

	run(&bb);

	return 0;
}