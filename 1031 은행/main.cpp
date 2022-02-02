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
		cout << "할로윈은행에 오신걸 환영합니다." << endl;
		cout << "===============================" << endl;
		cout << "[1] 신규가입" << endl;
		cout << "[2] 회원조회" << endl;
		cout << "[3] 입금" << endl;
		cout << "[4] 출금" << endl;
		cout << "[5] 계좌해지" << endl;
		cout << "[6] 종료" << endl;
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