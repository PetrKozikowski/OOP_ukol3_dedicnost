#include <iostream>
#include "client.h"
#include "Account.h"
#include "PartnerAccount.h"
#include "Bank.h"

using namespace std;


int main()
{
	const int NAME_COUNT = 10;
	const double INTEREST_RATE = 1.5;
	bool st;

	string prijmeni[NAME_COUNT] = {
		"Bjornsson",
		"Hall",
		"Shaw",
		"Stoltman",
		"Carter",
		"Kramer",
		"Jagger",
		"Jenkins",
		"Jones",
		"Jackson"
	};
		
	string jmeno[NAME_COUNT] = {
		"Peter",
		"Curtis",
		"Frank",
		"John",
		"Radim",
		"Mark",
		"Ferdinand",
		"Robert",
		"Ethan",
		"Ramon"
	};

	const int b1_clients_count = NAME_COUNT * NAME_COUNT;
	const int b1_accounts_count = NAME_COUNT * NAME_COUNT;
	Client* client1;
	Account* account1;
	PartnerAccount* partAccount1;
	Client* client;
	Client* lastClient = nullptr;
	Bank* bank1 = new Bank{ b1_clients_count, b1_accounts_count };
	// Vytvoøení sta klientù a sta úètù.
	
	cout <<  "*** TESTOVANI DEDICNOSTI ***" << endl << endl;
	cout << "*** Vytvoreni mnoziny uctu ***" << endl;
	for (int i = 0; i < NAME_COUNT; i++)
	{
		if (i == 2)
		{
			i = i * 2 / 2;

		}
		for (int j = 0; j < NAME_COUNT; j++)
		{
			string s1 = jmeno[j] + ' ' + prijmeni[i];
			string s2 = jmeno[(j + 1) % 10] + ' ' + prijmeni[i];
			client =  bank1->CreateClient(1000 + 10 * i + j, s1);
			if ((10 * i + j) % 2 != 0)
			{
				bank1->CreateAccount(50000 + 10 * i + j, client, lastClient, INTEREST_RATE/2);
			}
			else
			{
				bank1->CreateAccount(50000 + 10 * i + j, client, INTEREST_RATE);
			}
			lastClient = client;
		}

	}


	// Testování funkce GetClient
	cout << endl;
	cout << "*** Testovani funkce GetCode ***" << endl;
	client1 = bank1->GetClient(1050);
	cout << "client1 name: " << client1->GetName() << "  client1 code: " << client1->GetCode() << endl;

	// Testování funkce GetPartner
	cout << endl;
	
	// Testování funkce GetAccount
	cout << endl;
	cout << "*** Testovani funkce GetAccount ***" << endl;
	account1 = bank1->GetAccount(50050);
	if (account1->GetOwner() != nullptr)
	{
		account1->Deposit(1000.);
		//cout << "account1 owner: " << account1->GetOwner()->GetName() << "  account1 partner: " << account1->GetPartner()->GetName() << endl;     // GENERUJE CHYBU!
		//cout << "account1 number: " << account1->GetNumber() << "  account1 balance: " << account1->GetBalance() << "  account1 interestrate: " << account1->GetInterestRate() << endl;

		cout << "K uctu 50050 neni prirazen partner" << endl;
		cout << "account1 owner: " << account1->GetOwner()->GetName() << endl;
		cout << "account1 number: " << account1->GetNumber() << "  account1 balance: " << account1->GetBalance() << "  account1 interestrate: " << account1->GetInterestRate() << endl;
		bank1->AddInterest();
		cout << "Stav uctu: " << account1->GetBalance() << endl << endl;
	}

	cout << "*** Testovani funkce GetPartnerAccount ***" << endl;
	partAccount1  = bank1->GetPartnerAccount(50051);
	if (partAccount1->GetOwner() != nullptr && partAccount1->GetPartner() != nullptr)
	{
		partAccount1->Deposit(1000.);
		cout << "K uctu 50051 je prirazen partner" << endl;
		cout << "partAccount1 owner: " << partAccount1->GetOwner()->GetName() << "  partAccount1 partner: " << partAccount1->GetPartner()->GetName() << endl;
		cout << "partAccount1 number: " << partAccount1->GetNumber() << "  partAccount1 balance: " << partAccount1->GetBalance() << "  partAccount1 interestrate: " << partAccount1->GetInterestRate() << endl;
		bank1->AddInterest();
		cout << "Stav uctu po pricteni uroku: " << partAccount1->GetBalance() << endl;
	}
	/*cout << "*** Vkladame castku 1000 ***" << endl;
	partAccount1->Deposit(1000.);
	cout << "*** Lze vybrat 500? ***" << endl;
	st = partAccount1->CanWithdraw(500.);
	cout << "*** Lze vybrat 1500? ***" << endl;
	st = partAccount1->CanWithdraw(1500.);
	cout << "*** Pokus o vyssi vyber - 1500 ***" << endl;
	st = partAccount1->Withdraw(1500.);
	cout << "*** Pokus o vyber - 700 ***" << endl;
	st = partAccount1->Withdraw(700.);
	cout << "*** Pridani uroku ***" << endl;
	bank1->AddInterest();m

	cout << "Stav uctu po pricteni uroku: " << partAccount1->GetBalance() << endl;*/

	delete bank1;
 	getchar();

	return 0;

}