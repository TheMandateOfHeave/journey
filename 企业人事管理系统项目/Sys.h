#ifndef SYS_H
#define SYS_H

#include <iostream>
#include <string>
#include "contral.h"
using namespace std;

class Sys
{
public:
	Sys(){};
	~Sys(){};
	
	
	bool myregister();
	void mylogin();
	void login()
	{
		contral contral;
		contral.process();
	};
	void start();
private:
	string _name;
	string _passwd;
};

#endif