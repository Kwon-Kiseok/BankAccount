#pragma once

#define MAX_ACCOUNTS_SIZE 20
#define MAX_CUSTOMER_NAME 30

typedef struct
{
	int no;		//���¹�ȣ
	int money;	//�ܾ�
	char name[MAX_CUSTOMER_NAME];	//���̸�
}Account;

void CreateAccount(Account* accounts, int* idx);	// ���»���
void Deposit(Account* accounts);		// �Ա�
void Withdraw(Account* accounts);		// ���
void ViewInfo(Account* accounts);		// ��ȸ
void Save(Account* accounts, int* idx);			// ����
void Load(Account* accounts, int* idx);		// �ε�