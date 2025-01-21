#pragma once
#include "Headers.h"
class SignUp
{
public:

	void MakeNewAccount();
	void SaveAccountToFile(string& username, string& hashedPassword);
};

