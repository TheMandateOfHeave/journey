#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>

using namespace std;


class Node
{
    public:
      Node()
	  {
		  _next = NULL;
	  }
      Node* BuyNode(string name,string id,string date,string string,int limit);
    private:
      string  _name;
      string  _id;
      string  _date;
      string  _string;
      int  _limit;
      Node* _next;
      friend class List;
	  friend  class DataBase;
};

typedef class List
{
 public:
   List();
   List(List &src);
   List &operator=(List &src);
 private:
   Node _head;
   int _count;
   friend  class DataBase;
}*pList,List;


class DataBase
{
public:
	DataBase(){}
    static DataBase *getBase()
    {
        if( NULL == _Base)
        {
            _Base = new DataBase();
            return _Base;
        }
		return _Base;
    }
	void Insert(string name,string id,string date,string string,int limit);
	void Delete(string id);
	void Check(string id);
	void Change(string name,string id,string date,string string,int limit);
	void Show();
private:
	
static DataBase *_Base; 

List _list;

};

#endif
