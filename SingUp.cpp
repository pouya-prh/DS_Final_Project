#include "SignUp.h"

string HashPassword(const string& password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];

    SHA256(reinterpret_cast<const unsigned char*>(password.c_str()), password.size(), hash);

    // Convert hash to a hexadecimal string
    ostringstream oss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        oss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return oss.str();
}

void SignUp::MakeNewAccount()
{
	cout << "User name: ";
	string username;
	cin >> username;
	string password;
    cout << "Password: ";
	cin >> password;
    password = HashPassword(password);
    SaveAccountToFile(username, password);
}

void SignUp::SaveAccountToFile(string& username, string& hashedPassword)
{
   
    ifstream inputFile("accounts.json");
    json accounts;

    
    if (inputFile.is_open()) {
        inputFile >> accounts;
        inputFile.close();
    }

    accounts[username] = { {"password", hashedPassword}};

    
    ofstream outputFile("accounts.json");
    outputFile << setw(4) << accounts << endl;
    outputFile.close();
}
