#include "InputMoneyException.h"
#include <iostream>
InputMoneyException::InputMoneyException(int money)
	:mMoney(money)
{
}
void InputMoneyException::ShowMessage()
{
	std::cout << "InputMoney Exception Occur" << std::endl;
	std::cout << "�Էµ� �ݾ��� 0���� �۽��ϴ�." << std::endl;
	std::cout << "����� ����" << std::endl << std::endl;
	
}
