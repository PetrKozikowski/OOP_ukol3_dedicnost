#include <iostream>
#include <string>
#include "client.h"
#include "Account.h"
#include "PartnerAccount.h"


using namespace std;

Account::Account()
{
	this->number = 0;
	this->owner = nullptr;
	this->balance = 0;
	this->interestRate = 0;
}


Account::Account(int n, Client *o)
{
	this->number = n;
	this->owner = o;
	this->balance = 0;
	this->interestRate = 0;

}


Account::Account(int n, Client* o, double ir)
{
	this->number = n;
	this->owner = o;
	this->balance = 0;
	this->interestRate = ir;

}


Account::~Account()
{
}

int Account::GetNumber()
{
	return number;
}

Client* Account::GetOwner()
{
	return owner;
}


double Account::GetInterestRate()
{
	return interestRate;
}

double Account::GetBalance()
{
	return balance;
}

bool Account::CanWithdraw(double a)
{
	if (a > balance)
	{
		cout << "Nedostatek penez!" << " Stav uctu: " << balance << endl;
		return false;
	}
	cout << "Muzes vybrat: " << balance << endl;
	return true;
}

void Account::Deposit(double a)
{
	balance += a;
	cout << "Vlozeno: " << a << " Stav uctu: " << balance << endl;
}

bool Account::Withdraw(double a)
{
	if (CanWithdraw(a) == true)
	{
		balance -= a;
		cout << "Vybrano: " << a << " Stav uctu: " << balance << endl;
		return true;
	}
	cout << "Nelze vybrat!" << " Stav uctu: " << balance << endl;
	return false;
}

void Account::AddInterest()
{
	balance += balance * interestRate / 100;
}