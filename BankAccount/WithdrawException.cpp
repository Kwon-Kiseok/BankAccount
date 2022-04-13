#include "WithdrawException.h"
#include <iostream>
WithdrawException::WithdrawException(int money)
	: balance(money)
{
}
void WithdrawException::ShowMessage()
{
	std::cout << "Withdraw Exception occur" << std::endl;
	std::cout << "예금된 금액보다 더 많은 금액 출금 요청이 들어왔습니다." << std::endl;
	std::cout << "출금 실패" << std::endl << std::endl;
}
