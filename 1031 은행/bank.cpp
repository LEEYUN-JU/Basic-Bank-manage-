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
	
	cout << "이름을 입력하세요. >> ";
	cin.getline(name, sizeof(name));

	cout << "오늘 날짜를 입력해 주세요. >> ";
	cin.getline(date, sizeof(date));

	cout << "첫 예금 금액을 입력해 주세요. >> ";
	cin >> money;
	getchar();

	account* pmem = new account(name, date, money);

	if (size >= max)
	{
		cout << "회원이 되실 수 없습니다." << endl;
	}
	else
	{
		save_account[size] = pmem;
		size++;
		cout << "회원이 되신걸 축하합니다." << endl;
	}
}


void bank::printall()
{
	cout << "현재 회원 정보 : " << size << "명" << endl;
	cout << "     " << "이름\t" << "개설날짜\t" << "잔액\t\t" << "계좌번호\t" << endl;
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
	
	cout << "입금할 계좌번호를 입력해 주세요. >> ";
	cin >> get_account_number;
	getchar();

	for (int i = 0; i < size; i++)
	{
		if (account *pmem = save_account[i])
		{
			cout << "입금할 금액을 입력하세요. >> ";
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

	cout << "출금할 계좌번호를 입력해 주세요. >> ";
	cin >> get_account_number;
	getchar();

	for (int i = 0; i < size; i++)
	{
		if (account *pmem = save_account[i])
		{
			cout << "출금할 금액을 입력하세요. >> ";
			cin >> get_money;
			getchar();
			(*save_account[i]).add_withdraw(get_account_number, get_money);
		}
	}
}

void bank::byebye()
{
	cout << "다음에 또 뵙겠습니다." << endl;
}


void bank::delete_account()
{
	int get_account_number;

	while (true)
	{
		system("cls");
		cout << "계좌를 해지하시겠습니까? " << endl;
		cout << "맞으면 1번 아니시면 2번을 눌러주세요. >> " << endl;

		switch (_getch())
		{
		case'1': 
			cout << "해지할 계좌번호를 입력해 주세요. >> ";
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
