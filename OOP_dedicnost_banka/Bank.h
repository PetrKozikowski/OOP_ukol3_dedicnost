#pragma once
//#include "client.h"
//#include "Account.h"
#include "PartnerAccount.h"

class Bank
{
private:
	Client** clients;
	int clientsCount;

	Account** accounts;
	int accountsCount;

	PartnerAccount** partnerAccounts;
	int partnerAccountsCount;

public:
	Bank(int c, int a);
	~Bank();

	Client* GetClient(int c);
	Account* GetAccount(int n);
	PartnerAccount* GetPartnerAccount(int n);
	

	Client* CreateClient(int c, string n);
	Account* CreateAccount(int n, Client* c);
	Account* CreateAccount(int n, Client* c, double ir);
	PartnerAccount* CreateAccount(int n, Client* c, Client* p);
	PartnerAccount* CreateAccount(int n, Client* c, Client* p, double ir);

	void AddInterest();
	

};

