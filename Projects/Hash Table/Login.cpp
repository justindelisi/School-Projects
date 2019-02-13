///--------------------------------------------------------------------
///
///  Laboratory 11                                        Login.cpp
///
///  Application to verify username and password matching
///
///--------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "HashTable.cpp"

class login
{
public:
	///set key
	///Postcondition: Sets the key to username
	void setKey(const string &username);
	///Get key
	///Postcondition: returns the key
	string getKey() const;
	/// Set password
	///Postcondition: sets the password to password given
	void setPassword(const string &password);
	///Get password
	///Postcondition: returns the password
	string getPassword() const;
	///Hash
	///Postcondition: returns the hash array index based on the 
	///string input given
	static unsigned int hash(const string &str);

private:
	string key;
	string password;
};


void login::setKey(const string & username)
{
	key = username;
}

string login::getKey() const
{
	return key;
}


void login::setPassword(const string & password)
{
	this->password = password;
}


string login::getPassword() const
{
	return password;
}


unsigned int login::hash(const string & str)
{
	unsigned int val = 0;
	for (unsigned int i = 0; i < str.length(); ++i) 
	{
		val += str[i];
	}

	return val;
}

int main()
{
	HashTable<login, string> table(7);
	ifstream file("password.dat");
	login log;
	string username, password;
	
	file >> username;

	while (file.good())
	{
		file >> password;
		log.setKey(username);
		log.setPassword(password);
		table.insert(log);

		file >> username;
	}

	
	while (true)
	{
		cout << "Enter log in information or 0 to exit." << endl;
		cout << "Login: ";
		cin >> username;
		if (username == "0")
			return 0;
		cout << "Password: ";
		cin >> password;

		if (table.retrieve(username, log))
		{
			if (log.getPassword() == password)
			{
				cout << "Authentication successful." << endl;
			}
			else
				cout << "Authentication failure." << endl;
		}
		else
			cout << "Authentication failure. " << endl;
	}
	file.close();
	return 0;
}
