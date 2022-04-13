#include "InputMoneyException.h"
#include <iostream>
InputMoneyException::InputMoneyException(int money)
	:mMoney(money)
{
}
void InputMoneyException::ShowMessage()
{
	std::cout << "InputMoney Exception Occur" << std::endl;
	std::cout << "입력된 금액이 0보다 작습니다." << std::endl;
	std::cout << "입출금 실패" << std::endl << std::endl;
	
}
