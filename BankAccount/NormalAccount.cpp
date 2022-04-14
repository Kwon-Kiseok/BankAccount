#include "NormalAccount.h"

NormalAccount::NormalAccount() : mRatio(0)
{
}

NormalAccount::NormalAccount(int no, int money, const my::string name, int ratio)
	: Account(no, money, name), mRatio(ratio) {}

NormalAccount::NormalAccount(const NormalAccount& copy)
	: Account(copy), mRatio(copy.mRatio) {}

NormalAccount::~NormalAccount() {}

NormalAccount& NormalAccount::operator=(const NormalAccount& ref)
{
	delete& mName;
	mName = nullptr;

	mName = my::string(ref.mName);
	mNo = ref.mNo;
	mMoney = ref.mMoney;

	return *this;
}

int NormalAccount::GetRatio() const
{
	return mRatio;
}

void NormalAccount::Deposit(int money)
{
	money += GetInterest();
	Account::Deposit(money);
	// protected�� ������� �޾ƿͼ� �׳� ���ؿ͵� ��
}

int NormalAccount::GetInterest() const
{
	return (Account::GetMoney() * mRatio / 100);
}