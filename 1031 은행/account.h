#pragma once

#include <string>
using namespace std;

class account
{
	static int account_number;
	static int autonumber;

	int a_number;
	int number;
	string name;
	int money;
	string date;

public:
	account(string _name, string _date, int _money);
	~account();

public:
	void print() const;
	void add_saving(int _account, int _money);
	void add_withdraw(int _account, int _money);
	void delete_account(int _account);
};

