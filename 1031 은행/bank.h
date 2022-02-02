#pragma once

#include "account.h"

class bank
{
	account* *save_account;
	int max;
	int size;

public:
	bank(int _max = 10);
	~bank();

public:	
	void insert();
	void printall();
	void saving();
	void withdraw();
	void byebye();
	void delete_account();
};

