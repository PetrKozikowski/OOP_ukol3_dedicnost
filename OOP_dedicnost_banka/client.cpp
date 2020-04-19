#include <string>
#include "client.h"

using namespace std;

Client::Client(int c, string n)
{
	code = c;
	name = n;
}

Client::~Client()
{

}

int Client::GetCode()
{
	return code;
}

string Client::GetName()
{
	return name;
}