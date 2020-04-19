#include <iostream>
#include <stdio.h>
#include "Account.h"
#include "client.h"
#include "PartnerAccount.h"

using namespace std;

PartnerAccount::PartnerAccount(int n, Client* o, Client* p) : Account(n, o)
{
	this->partner = p;
}

PartnerAccount::PartnerAccount(int n, Client* o, Client* p, double ir) : Account(n, o, ir)
{
	this->partner = p;
}

Client* PartnerAccount::GetPartner()
{
	return partner;
}
