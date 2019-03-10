#ifndef VIEW_H
#define VIEW_H
#include <iostream>
#include "DataBase.h"
using namespace std;
class view
{
public:
	view(){}
	static void Insert();
	static void Delete();
	static void Check();
	static void Change();
	static void Show();
private:
	friend class ModelNode;
};

#endif