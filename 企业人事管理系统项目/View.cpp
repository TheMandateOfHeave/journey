#include "View.h"
#include <string>


void view::Insert()
{
	cout << "please input your data to insert,if no please input wu"<<endl;
	cout << "name    id   date   string    limit"  <<  endl;
	string name;
	cin >> name;
	string id;
	cin >> id;
	string date;
	cin >> date;
	string string;
	cin >> string;
	int limit;
	cin >> limit;
	DataBase::getBase()->Insert(name,id,date,string,limit);
}


void view::Delete()
{
	cout<< "please input your id to delete" <<endl;
	string id;
	cin >> id;
	DataBase::getBase()->Delete(id);
}

void view::Check()
{
	cout<< "please input your id to check" <<endl;
	string id;
	cin >> id;
	DataBase::getBase()->Check(id);
}


void view::Change()
{
	cout << "please input your data to change,if no please input wu"<<endl;
	cout << "name    id   date   string    limit"  <<  endl;
	string name;
	cin >> name;
	string id;
	cin >> id;
	string date;
	cin >> date;
	string string;
	cin >> string;
	int limit;
	cin >> limit;
	DataBase::getBase()->Change(name,id,date,string,limit);
}


void view::Show()
{
	DataBase::getBase()->Show();
}