#include <string>
#include <iostream>
#include "client.h"
#include "Account.h"
#include "Bank.h"

using namespace std;

Bank::Bank(int c, int a)
{
	clientsCount = c;
	accountsCount = a;
	partnerAccountsCount = a;
	clients = new Client * [clientsCount] {};
	accounts = new Account * [accountsCount] {};
	partnerAccounts = new PartnerAccount * [partnerAccountsCount] {};
}

Bank::~Bank()
{
	for (int i = 0; i < accountsCount; i++)
	{
		if (accounts[i] == nullptr)
		{
			break;
		}
		else
		{
			delete accounts[i];
		}	
	}
	delete[] accounts;

	for (int i = 0; i < partnerAccountsCount; i++)
	{
		if (partnerAccounts[i] == nullptr)
		{
			break;
		}
		else
		{
			delete partnerAccounts[i];
		}
	}
	delete[] partnerAccounts;


	for (int i = 0; i < clientsCount; i++)
	{
		if (clients[i] == nullptr)
		{
			break;
		}
		else
		{
			delete clients[i];
		}

	}
	delete[] clients;
}

Client* Bank::GetClient(int c)
{
	for (int i = 0; i < clientsCount; i++)
	{
		if (clients[i] == nullptr)
		{
			cout << "Klient neexistuje" << endl;
			return nullptr;
		}
		else if (clients[i]->GetCode() == c)
		{
			cout << "Klient existuje" << endl;
			return clients[i];
		}
	}
	cout << "Klient neexistuje" << endl;
	return nullptr;
}

PartnerAccount* Bank::GetPartnerAccount(int n)
{
	for (int i = 0; i < partnerAccountsCount; i++)
	{
		if (partnerAccounts[i] == nullptr)
		{
			cout << "Ucet neexistuje" << endl;
			return nullptr;
		}
		else if (partnerAccounts[i]->GetNumber() == n)
		{
			cout << "Ucet existuje" << endl;
			return partnerAccounts[i];
		}
	}
	cout << "Ucet neexistuje" << endl;
	return nullptr;
}

Account* Bank::GetAccount(int n)
{
	for (int i = 0; i < accountsCount; i++)
	{
		if (accounts[i] == nullptr)
		{
			cout << "Ucet neexistuje" << endl;
			return nullptr;
		}
		else if (accounts[i]->GetNumber() == n)
		{
			cout << "Ucet existuje" << endl;
			return accounts[i];
		}
	}
	cout << "Ucet neexistuje" << endl;
	return nullptr;
}

Client* Bank::CreateClient(int c, string n)
{
	for (int i = 0; i < clientsCount; i++)
	{
		if (clients[i] == nullptr)
		{
			clients[i] = new Client(c, n);
			cout << "CreateClient: " << "c: " << c << " n: " << n << endl;
			return clients[i];
		}
		else if (clients[i]->GetCode() == c)
		{
			if (clients[i]->GetName().compare(n) != 0)
			{
				cout << "Cislo a jmeno klienta nesouhlasi" << endl;
				return nullptr;
			}
			else
			{
				cout << "Klient existuje" << endl; 
				return clients[i];
			}
		}

	}
	cout << "Seznam klientu je plny" << endl;
	return nullptr;
}

Account* Bank::CreateAccount(int n, Client* c)
{
	Account* account = CreateAccount(n, c, 0.);
	return account;	
}

PartnerAccount* Bank::CreateAccount(int n, Client* c, Client* p)
{
	PartnerAccount* account = new PartnerAccount(n, c, p);
	return account;
}

Account* Bank::CreateAccount(int n, Client* c, double ir)
{
	for (int i = 0; i < accountsCount; i++)
	{
		if (accounts[i] == nullptr)
		{
			accounts[i] = new Account(n, c, ir);
			if (c != nullptr)
			{
				cout << "CreateAccount: " << "n: " << n << " c: " << c->GetCode() << " ir: " << ir << endl;
			}
			return accounts[i];
			
		}
		else if (accounts[i]->GetNumber() == n)
		{
			if (accounts[i]->GetOwner()->GetCode() != c->GetCode())
			{
				cout << "Nesouhlasi cisla vlastniku" << endl;
				return nullptr;
			}
			else
			{
				cout << "Ucet existuje" << endl;
				return accounts[i];
			}
		}

	}
	cout << "Seznam uctu je plny" << endl;
	return nullptr;
}

PartnerAccount* Bank::CreateAccount(int n, Client* c, Client* p, double ir)
{
	for (int i = 0; i < partnerAccountsCount; i++)
	{
		if (partnerAccounts[i] == nullptr)
		{
			partnerAccounts[i] = new PartnerAccount(n, c, p, ir);
			if (c != nullptr && p != nullptr)
			{
				cout << "CreateAccount: " << "n: " << n << " c: " << c->GetCode() << " p: " << p->GetCode() << " ir: " << ir << endl;
			}
			else if (c != nullptr)
			{
				cout << "CreateAccount: " << "n: " << n << " c: " << c->GetCode() << " ir: " << ir << endl;
			}
			return partnerAccounts[i];

		}
		else if (partnerAccounts[i]->GetNumber() == n)
		{
			if (partnerAccounts[i]->GetOwner()->GetCode() != c->GetCode())
			{
				cout << "Nesouhlasi cisla vlastniku" << endl;
				return nullptr;
			}
			else
			{
				cout << "Ucet existuje" << endl;
				return partnerAccounts[i];
			}
		}

	}
	cout << "Seznam uctu je plny" << endl;
	return nullptr;
}

void Bank::AddInterest()
{
	for (int i = 0; i < accountsCount; i++)
	{
		if (accounts[i] == nullptr)
		{
			break;
		}
		else
		{
			accounts[i]->AddInterest();
		}	
	}
	for (int i = 0; i < partnerAccountsCount; i++)
	{
		if (partnerAccounts[i] == nullptr)
		{
			return;
		}
		else
		{
			partnerAccounts[i]->AddInterest();
		}
	}

}
	