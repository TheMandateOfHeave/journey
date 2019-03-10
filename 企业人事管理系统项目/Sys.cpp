#include "Sys.h"
#include "contral.h"
#include <string>
#include <string.h>
#include <fstream>

bool Sys::myregister()
{
	string _name;
	cout<<"please input your name" <<endl;
	cin >> _name;
	string _passwd;
	cout<<"please input your passwd" <<endl;
	cin >> _passwd;
	cout<<"please input your data" << endl;
	FILE *fpna = NULL;
	FILE *fppd = NULL;

	fpna = fopen("D:\\register.txt","a+");
	fppd = fopen("D:\\passwd.txt","a+");
	string JudgeName = ",";
	string JudgePasswd = ",";
	string::size_type na;
	string::size_type pd;
	na = _name.find(JudgeName);
	pd = _passwd.find(JudgePasswd);
	if( (na != string::npos) || (pd != string::npos ) )
	{
		cout << "please input correct data\n" << endl;
		return 0;
	}

	//先对文档中的切割处理，判断原文本是否有同名的用户名，如果有，则返回0
/*	
//这是分割时出现了问题
	int i=0;                             //创建足够大的数组去保存文本数据的值
	int t=0;
	int temp = 0;
	ifstream file("register.txt");
	streampos fsize = file.tellg();
	file.seekg(0, ios::end);
	size_t filesize = file.tellg() - fsize;
	file.seekg(fsize);
	char* str = new char[filesize + 1];
	file.getline(str, filesize + 1);
	cout << str << endl;


	
    char *p;                           //判断用户名是否已被注册
	p = strtok(str,",");
	int sign=0;
	char *account[20];
	while( p != NULL )
	{
		account[sign++] = p;
		cout<< p << endl;
		p = strtok(str,",");
	}
	
	while( sign > 0)
	{
		if( _name == account[sign])
		{
			cout << "the name have been registered" <<endl;
			return 0;
		}
		sign--;
	}*/





	string dealname = ",";
	dealname += _name;

	string dealpasswd = ",";
	dealpasswd += _passwd;
	//cout<<dealname<<endl;
	//cout<<dealpasswd<<endl;
	fprintf(fpna,"%s",dealname.c_str());
	fprintf(fppd,"%s",dealpasswd.c_str());
	fclose(fpna);
	fclose(fppd);
	
	cout<<"create id successful" << endl;

	return 1;
}


void Sys::mylogin()
{

	string _name;
	cout<<"please input your name" <<endl;
	cin >> _name;
	string _passwd;
	cout<<"please input your passwd" <<endl;
	cin >> _passwd;

	int i=0;                             //创建足够大的数组去保存文本数据的值
	int t=0;
	int temp = 0;
	ifstream file("register.txt");
	streampos fsize = file.tellg();
	file.seekg(0, ios::end);
	size_t filesize = file.tellg() - fsize;
	file.seekg(fsize);
	char* str = new char[filesize + 1];
	file.getline(str, filesize + 1);
	cout<<str<<endl;
	char *p;                          
	p = strtok(str,",");
	int sign=0;
	char *account[20];
	while( p != NULL )
	{
		account[sign++] = p;
		cout<< p << endl;
		p = strtok(str,",");
	}
	
	while( sign > 0)
	{
		if( _name == account[sign])
		{
			break;
		}
		sign--;
	}


	i=0;                            
	t=0;
	temp = 0;
	ifstream file2("passwd.txt");
	streampos fsize2 = file2.tellg();
	file2.seekg(0, ios::end);
	size_t filesize2 = file2.tellg() - fsize2;
	file2.seekg(fsize2);
	char* str2 = new char[filesize2 + 1];
	file2.getline(str2, filesize2 + 1);

	char *s;                          
	s = strtok(str2,",");
	int sign2=0;
	char *account2[20];
	while( p != NULL )
	{
		account2[sign2++] = p;
		cout<< p << endl;
		p = strtok(str2,",");
	}

/*	if( _passwd != account2[sign])
	{
		cout<<"passwd error\n"<<endl;
		return 0;
	}
	*/

	
	return ;
}


void Sys::start()
{
	cout<<"0:register   "<<"1:login   "<<"2:exit    "<<endl;
	string c;
	cin>>c;
	if( c == "0")
	{
		Sys::myregister();
		Sys::mylogin();
		contral contral;
	    contral.process();

	}
	else if( c == "1")
	{
		Sys::mylogin();
	}
	else if( c == "2")
	{
		return;
	}
	else
	{
		cout<<"please input right chose"<<endl;
	}
}