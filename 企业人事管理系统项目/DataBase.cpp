#include "DataBase.h"
#include <string>
DataBase* DataBase::_Base = NULL;
List::List()
{
	_count = 0;
}

List::List(List &src)
{
	Node *p = src._head._next;

	for( int i=0;i<src._count;i++)
	{
		Node *q = &_head;
		for( int j=0;j<_count;j++)
		{
			q = q->_next;
		}
		Node *s = new Node;
		s->_name = p->_name;
		s->_id = p->_id;
		s->_date = p->_date;
		s->_string = p->_string;
		s->_limit = p->_limit;
		s->_next = p->_next;
		q->_next = s;
		_count++;
		p = p->_next;
	}
}

List & List::operator=(List &src)
{
	if( this == &src)
	{
		return *this;
	}

	if( NULL != _head._next)
	{
		delete _head._next;
	}

	Node *p = src._head._next;
	return *this;
}

//Node*  Node::BuyNode(string name,string id,string date,string string,int limit)
//{
//		  Node *p = new Node;
//		  p->_name = name;
//		  p->_id = id;
//		  p->_date = date;
//		  p->_string = string;
//		  p->_limit = limit;
//		  p->_next = NULL;
//		  return p;
//}

void DataBase::Insert(string name,string id,string date,string string,int limit)
{
	Node *p = &_list._head;
	while ( p->_next != NULL)
	{
		p = p->_next;
	}
	Node *s = new Node;
	s->_name = name;
	s->_id = id;
	s->_date = date;
	s->_string = string;
	s->_limit = limit;
	s->_next = p->_next;
	p->_next = s;
	_list._count++;
}

void DataBase::Delete(string id)
{
	Node *s = &_list._head;
	Node *p = s;
	while( (id != s->_id)  && ( s != NULL ) ) 
	{
		p = s;
		s = s->_next;
	}

	if( s == NULL )
	{
		printf("dot not have the id\n");
		return;
	}
	else
	{
		p->_next = s->_next;
		delete s;
		cout<<"delete success" << endl;
		_list._count--;
	}
	return;
}

void DataBase::Change(string name,string id,string date,string string,int limit)
{
	Node *s = &_list._head;
	while( (id != s->_id)  && ( s != NULL ) ) 
	{
		s = s->_next;
	}

	if( s == NULL )
	{
		printf("id not found\n");
		return;
	}
	else
	{
		if( name !=  "wu" )
		{
			s->_name = name;
		}

		if( date !=  "wu" )
		{
			s->_date = date;
		}

		if( string !=  "wu")
		{
			s->_date = string;
		}

		if( limit != -1 )
		{
			s->_limit = limit;
		}

		cout << "Change success" << endl;
	}
}


void DataBase::Check(string id)
{
	Node *s = &_list._head;
	while( (id != s->_id)  && ( s != NULL ) ) 
	{
		s = s->_next;
	}

	if( s == NULL )
	{
		printf("id not found\n");
		return;
	}
	else
	{
		cout <<s->_name<<"    ";
		cout <<s->_id <<"    ";
		cout <<s->_date <<"    ";
		cout <<s->_string <<"    ";
		cout <<s->_limit <<"    ";
	}
}

void DataBase::Show()
{
	Node*s = _list._head._next;
	while( s != NULL )
	{
		cout<<s->_name<<"    ";
		cout<<s->_id<<"    ";
		cout<<s->_date<<"    ";
		cout<<s->_string<<"    ";
		cout<<s->_limit<<"    ";
		cout<<endl;
		s = s->_next;
	}

}