#include "WithdrawException.h"
#include <iostream>
WithdrawException::WithdrawException(int money)
	: balance(money)
{
}
void WithdrawException::ShowMessage()
{
	std::cout << "Withdraw Exception occur" << std::endl;
	std::cout << "���ݵ� �ݾ׺��� �� ���� �ݾ� ��� ��û�� ���Խ��ϴ�." << std::endl;
	std::cout << "��� ����" << std::endl << std::endl;
}
