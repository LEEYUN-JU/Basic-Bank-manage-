#include <iostream>
using namespace std;
#include "bank.h"
#include "account.h"
#include <conio.h>

bank::bank(int _max)
{
	max = _max;
	size = 0;
	save_account = new account*[max];
}

bank::~bank()
{
}

void bank::insert()
{
	char name[20];
	char date[20];
	int money;
	
	cout << "�̸��� �Է��ϼ���. >> ";
	cin.getline(name, sizeof(name));

	cout << "���� ��¥�� �Է��� �ּ���. >> ";
	cin.getline(date, sizeof(date));

	cout << "ù ���� �ݾ��� �Է��� �ּ���. >> ";
	cin >> money;
	getchar();

	account* pmem = new account(name, date, money);

	if (size >= max)
	{
		cout << "ȸ���� �ǽ� �� �����ϴ�." << endl;
	}
	else
	{
		save_account[size] = pmem;
		size++;
		cout << "ȸ���� �ǽŰ� �����մϴ�." << endl;
	}
}


void bank::printall()
{
	cout << "���� ȸ�� ���� : " << size << "��" << endl;
	cout << "     " << "�̸�\t" << "������¥\t" << "�ܾ�\t\t" << "���¹�ȣ\t" << endl;
	cout << "------------------------------------------" << endl;
	for (int i = 0; i < size; i++)
	{
		account *pmem = save_account[i];
		pmem->print();
	}
}

void bank::saving()
{
	int get_account_number;
	int get_money;
	
	cout << "�Ա��� ���¹�ȣ�� �Է��� �ּ���. >> ";
	cin >> get_account_number;
	getchar();

	for (int i = 0; i < size; i++)
	{
		if (account *pmem = save_account[i])
		{
			cout << "�Ա��� �ݾ��� �Է��ϼ���. >> ";
			cin >> get_money;
			getchar();
			(*save_account[i]).add_saving(get_account_number, get_money);
		}
	}
}

void bank::withdraw()
{
	int get_account_number;
	int get_money;

	cout << "����� ���¹�ȣ�� �Է��� �ּ���. >> ";
	cin >> get_account_number;
	getchar();

	for (int i = 0; i < size; i++)
	{
		if (account *pmem = save_account[i])
		{
			cout << "����� �ݾ��� �Է��ϼ���. >> ";
			cin >> get_money;
			getchar();
			(*save_account[i]).add_withdraw(get_account_number, get_money);
		}
	}
}

void bank::byebye()
{
	cout << "������ �� �˰ڽ��ϴ�." << endl;
}


void bank::delete_account()
{
	int get_account_number;

	while (true)
	{
		system("cls");
		cout << "���¸� �����Ͻðڽ��ϱ�? " << endl;
		cout << "������ 1�� �ƴϽø� 2���� �����ּ���. >> " << endl;

		switch (_getch())
		{
		case'1': 
			cout << "������ ���¹�ȣ�� �Է��� �ּ���. >> ";
			cin >> get_account_number;
			getchar(); 
			for (int i = 0; i < size; i++)
			{
				(*save_account[size]).delete_account(get_account_number);
				size--;
			}
			break;
		case'2': return;
		}
		system("pause");
	}

}
