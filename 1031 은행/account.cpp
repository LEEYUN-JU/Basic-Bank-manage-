#include <iostream>
using namespace std;
#include "account.h"

int account::account_number = 1000;
int account::autonumber = 0;

account::account(string _name, string _date, int _money)
{
	a_number = account_number;
	
	autonumber++;

	number = autonumber;
	name = _name;
	date = _date;
	money = _money;

	account_number += 10;
}

account::~account()
{
}

void account::print() const
{
	cout << "[" << number << "]  ";
	cout << name << "\t";
	cout << date << "\t\t";
	cout << money << "\t\t";
	cout << a_number << endl;
}

void account::add_saving(int _account, int _money)
{
	if (account_number == _account)
	{
		money += _money;
	}
	else
		cout << "일치하는 계좌번호가 없습니다." << endl;
}

void account::add_withdraw(int _account, int _money)
{
	if (account_number == _account)
	{
		money -= _money;
	}
	else
		cout << "일치하는 계좌번호가 없습니다." << endl;
}

void account::delete_account(int _account)
{
	if (account_number == _account)
	{
		name = "\0";
		date = "\0";
		
	}
}
