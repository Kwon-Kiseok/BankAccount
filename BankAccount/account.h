#pragma once

#define MAX_ACCOUNTS_SIZE 20
#define MAX_CUSTOMER_NAME 30

typedef struct
{
	int no;		//계좌번호
	int money;	//잔액
	char name[MAX_CUSTOMER_NAME];	//고객이름
}Account;

void CreateAccount(Account* accounts, int* idx);	// 계좌생성
void Deposit(Account* accounts);		// 입금
void Withdraw(Account* accounts);		// 출금
void ViewInfo(Account* accounts);		// 조회
void Save(Account* accounts, int* idx);			// 저장
void Load(Account* accounts, int* idx);		// 로드